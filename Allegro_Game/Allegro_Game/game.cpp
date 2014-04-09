#include <allegro.h>
#include <string>
#include <vector>
#include <time.h>

#include "Game.h"
#include "entity.h"
#include "Bullet.h"
#include "Ship.h"
#include "mine.h"

extern volatile int timer;

int Game::run()
{

	srand(time(NULL));

	
	BITMAP* bg = load_bitmap("gameBackground.bmp",NULL);
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
	SAMPLE* fire = load_sample("laser1.wav");
	Ship *playerShip = new Ship("ship.bmp",SCREEN_W / 2,SCREEN_H / 2,0,1,2);
	
	std::vector<EnemyShip*> enemyShips;
	std::vector<Bullet*> bullets;
	std::vector<Mine*> mines;
	mines.push_back( new Mine("mine.bmp", 45, 45));
	
	

	const int ALLEGRO_RIGHT_ANGLE = 256 / 4;
	
	//delays
	bool canFire = true;
	bool canRotate = true;

	const int IN_PROGRESS = 0;
	const int USER_EXIT = 1;
	const int WIN = 2;
	const int LOSE = 3;

	int gameStatus = IN_PROGRESS;
	int enemiesDestroyed = 0;

	int delay = 0;
	spawnEnemy(enemyShips, enemiesDestroyed);

	while(gameStatus == IN_PROGRESS)
	{
		while(timer)
		{
			checkKeyboard(playerShip);
			if (canRotate)
			{
				canRotate = checkRotate(playerShip);
			}
			
			if (canFire)
			{
				canFire = checkFire(playerShip, bullets);
				if (!canFire)
				{
					play_sample(fire,255,128,1000,0);
				}
			}
			
			checkBoundries(playerShip);
			checkBoundries(enemyShips[0]);

			draw_sprite(buffer, bg, 0, 0);
		
			//temp
			//for(int i = 0; i < enemyShips.size(); i++)
			
			/*Have counter check how many enemy ships have been deployed once 5 have been spawned trigger
			game over and show score, bullet to ship collision should trigger the next ship.
			*/

			for (int i = 0; i < bullets.size(); i++)
			{
				bullets[i]->update();
			}

			

			/*if (!collisionTest(playerShip,mines[0]))
			{
				draw_sprite(buffer, mines[0]->getSprite(), mines[0]->getX(),mines[0]->getY());
			}*/

			if (enemyShips.size() > 0)
			{
				enemyShips[0]->update();
				rotate_sprite(buffer,enemyShips[0]->getSprite(),enemyShips[0]->getX(),enemyShips[0]->getY(),
					itofix(enemyShips[0]->getDirection() * ALLEGRO_RIGHT_ANGLE));
				if (collisionTest(playerShip,enemyShips[0]))
				{
					playerShip->hit(1); 
				}
				for (int i = 0; i < bullets.size(); i++)
				{
					if (collisionTest(enemyShips[0],bullets[i]))
					{
						enemyShips[0]->hit(1);
						bullets[i]->hit(1);

						if (enemyShips[0]->isDestroyed())
						{
							enemyShips.erase(enemyShips.begin());
							gameStatus = spawnEnemy(enemyShips, enemiesDestroyed);

							bullets.clear();
						}


					}
				}
			}

			rotate_sprite(buffer, playerShip->getSprite(),playerShip->getX(),playerShip->getY(), 
				itofix(playerShip->getDirection() * ALLEGRO_RIGHT_ANGLE));

			// draw collision bounding box
			/*rect(buffer, playerShip->getX(), playerShip->getY(), playerShip->getX() + playerShip->getSprite()->w,
				playerShip->getY()+playerShip->getSprite()->h, makecol(255,255,255));*/

			

			for (int i = 0; i < bullets.size(); i++)
			{
				circle(buffer, bullets[i]->getX(), bullets[i]->getY(), 3, makecol(255,255,255));
			}

			if(key[KEY_ESC]) {
				gameStatus = USER_EXIT;
			}
			
			if(playerShip->isDestroyed())
			{
				gameStatus = LOSE;
			}

			
			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--;
			delay++;
		}
		
		if (delay > 30) 
		{
			canFire = true;
			canRotate = true;
			delay = 0;
		}
	}

	destroy_bitmap(buffer);
	destroy_sample(fire);

	if (gameStatus != USER_EXIT)
	{
		//load game over here
	}

	return 0;
}

int Game::spawnEnemy(std::vector<EnemyShip*> &enemyShips, int enemiesDestroyed)
{
	const int FACING_UP = 0;
	const int FACING_RIGHT = 1;
	const int FACING_DOWN = 2;
	const int FACING_LEFT= 3;

	if (enemiesDestroyed > 5)
	{
		return 2; //returns a win status to the game loop
	}

	enemyShips.push_back(new EnemyShip("enemyShip.bmp",350,200,0,5,3));

	// Assign a random direction for the ship to spawn from
	int direction = randomNumber(0,3);
	xyPos pos;

	int width = enemyShips[0]->getWidth();
	int height = enemyShips[0]->getHeight();

	switch (direction)
	{
	case FACING_UP:
		pos.x = randomNumber(0, SCREEN_W - width);
		pos.y = SCREEN_H;
		break;
	case FACING_RIGHT:
		pos.x = 0 - width;
		pos.y = randomNumber(0, SCREEN_H - height);
		break;
	case FACING_DOWN:
		pos.x = randomNumber(0, SCREEN_W - width);
		pos.y = 0 - width;
		break;
	case FACING_LEFT:
		pos.x = SCREEN_W; 
		pos.y = randomNumber(0, SCREEN_H - height);
		break;
	}

	enemyShips[0]->setDirection(direction);
	enemyShips[0]->teleport(pos.x,pos.y);

	return 0;
}

void Game::checkKeyboard(Ship *playerShip)
{
	if (key[KEY_W] || key[KEY_UP])
	{
		//ship_y -= speed;
		playerShip->movePos('U');
	}
	if (key[KEY_S] || key[KEY_DOWN])
	{
		//ship_y += speed;
		playerShip->movePos('D');
	}
	if (key[KEY_A] || key[KEY_LEFT])
	{
		//ship_x -= speed;
		playerShip->movePos('L');
	}
	if (key[KEY_D] || key[KEY_RIGHT])
	{
		//ship_x += speed;
		playerShip->movePos('R');
	}

}
bool Game::checkRotate(Ship *playerShip)
{
	//ROTATION (NEEDS WORK)
	if (key[KEY_Q])
	{
		rotate4(false,playerShip);
		//rotate left
		return false;
	}
	if (key[KEY_E])
	{
		rotate4(true,playerShip);
		//rotate right
		return false;
	}
	
	return true;
}

bool Game::checkFire(Ship *playerShip, std::vector<Bullet*> &bullets)
{
	if (key[KEY_SPACE])
	{
		//remove oldest bullet after 5 other bullets are in memory
		if (bullets.size() > 7){
			bullets.erase(bullets.begin());
		}

		// add new bullet to end of vector
		bullets.push_back(new Bullet(playerShip->getTurretX(), playerShip->getTurretY(),
			playerShip->getDirection(),1));

		//Player loses a point, this is to try and deter bullet 'spamming'
		score -= 1;
		return false;
	}
	
	return true;
}

void Game::rotate4(bool clockwise, Ship *playerShip)
{
	if (clockwise)
	{
		if (playerShip->getDirection() == 3)
		{
			playerShip->setDirection(0);
		}
		else
		{
			playerShip->setDirection(true);
		}
	}
	else
	{
		if (playerShip->getDirection() == 0)
		{
			playerShip->setDirection(3);
		}
		else
		{
			playerShip->setDirection(false);
		}
	}
}

void Game::getFourCorners(Entity *object, std::vector<Game::xyPos> &objVec)
{
	/*
	Diagram of vector index's actual locations 
	0-----1
	|     |
	|     |
	|     |
	2-----3

	*/

	// Fetch objects dimension and coordinates to avoid multiple recalls.
	int width = object->getWidth();
	int height = object->getHeight();
	Game::xyPos origin;

	if (object->isCircle())
	{
		//This offsets the x and y coordinate to the top left, rather than the center.
		origin.x = object->getX() - (width / 2);
		origin.y = object->getY() - (height / 2);
	}
	else
	{
		origin.x = object->getX();
		origin.y = object->getY();
	}

	//0 - TopLeft
	objVec[0].x = origin.x;
	objVec[0].y = origin.y;
	//1 - TopRight
	objVec[1].x = origin.x + width;
	objVec[1].y = origin.y;
	//2 - BottomLeft
	objVec[2].x = origin.x;
	objVec[2].y = origin.y + height;
	//3 - BottomRight
	objVec[3].x = origin.x + width;
	objVec[3].y = origin.y + height;
	
}


// Refer to design documentation for more in depth details on this function
bool Game::collisionTest(Entity *object1, Entity *object2)
{
	//Created a vector array to store the coordinates of the objects.
	std::vector< std::vector<Game::xyPos> > objVec; //Multi dimensional vector 
	objVec.resize(2);
	objVec[0].resize(4);
	objVec[1].resize(4);

	getFourCorners(object1, objVec[0]);
	getFourCorners(object2, objVec[1]);

	// X coordinate collision test
	if (objVec[0][0].x < objVec[1][1].x && 
		objVec[0][1].x > objVec[1][0].x )
	{
		// Y coordinate collision test
		if (objVec[0][0].y < objVec[1][2].y &&
			objVec[0][2].y > objVec[1][0].y)
		{
			return true;
		}

	}

	return false;

}

int Game::randomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Game::checkBoundries(Ship* shipObject)
{
	std::vector<Game::xyPos> shipPoints;
	shipPoints.resize(4);
	getFourCorners(shipObject, shipPoints);

	if (shipPoints[2].y < 0)
	{
		shipObject->teleport(shipObject->getX(),SCREEN_H - 1);
	}
	else if (shipPoints[0].y > SCREEN_H)
	{
		shipObject->teleport(shipObject->getX(),1 - shipObject->getHeight());
	}

	if (shipPoints[0].x > SCREEN_W)
	{
		shipObject->teleport(1 - shipObject->getWidth(),shipObject->getY());
	}
	else if (shipPoints[1].x < 0)
	{
		shipObject->teleport(SCREEN_W - 1,shipObject->getY());
	}
}
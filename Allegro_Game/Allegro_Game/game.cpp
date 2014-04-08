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

Game::Game()
{
	//Game::xyPos xyPosInst;
}

void Game::run()
{

	srand(time(NULL));

	BITMAP* bg = load_bitmap("gameBackground.bmp",NULL);
	buffer = create_bitmap(SCREEN_W,SCREEN_H);

	Ship *playerShip = new Ship("ship.bmp",SCREEN_W / 2,SCREEN_H / 2,100,2,1);
	
	std::vector<Bullet*> bullets;
	std::vector<Mine*> mines;
	mines.push_back( new Mine("mine.bmp", 45, 45));
	
	bool endGame = false;

	const int ALLEGRO_RIGHT_ANGLE = 256 / 4;

	while(!endGame)
	{
		while(timer)
		{
			checkKeyboard(playerShip);
			checkRotate(playerShip);
			checkFire(playerShip, bullets);


			for (int i = 0; i < bullets.size(); i++)
			{
				bullets[i]->update();
			}

			draw_sprite(buffer, bg, 0, 0);

			if (!collisionTest(playerShip,mines[0]))
			{
				draw_sprite(buffer, mines[0]->getSprite(), mines[0]->getX(),mines[0]->getY());
			}

			rotate_sprite(buffer, playerShip->getSprite(),playerShip->getX(),playerShip->getY(), 
				itofix(playerShip->getDirection() * ALLEGRO_RIGHT_ANGLE));

			// draw collision bounding box
			rect(buffer, playerShip->getX(), playerShip->getY(), playerShip->getX() + playerShip->getSprite()->w,
				playerShip->getY()+playerShip->getSprite()->h, makecol(255,255,255));

			

			for (int i = 0; i < bullets.size(); i++)
			{
				circle(buffer, bullets[i]->getX(), bullets[i]->getY(), 3, makecol(255,255,255));
			}

			if(key[KEY_ESC]) {
				endGame = true;
			}
			
			
			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--;
		}
	}

	destroy_bitmap(buffer);
}

void Game::spawnEnemy(EnemyShip *object)
{
	const int FACING_UP = 0;
	const int FACING_RIGHT = 1;
	const int FACING_DOWN = 2;
	const int FACING_LEFT= 3;

	object = new EnemyShip()

	// Assign a random direction for the ship to spawn from
	int direction = randomNumber(0,3);
	xyPos pos;
	switch (direction)
	{
	case FACING_UP:
		pos.x = randomNumber(0, SCREEN_W /* - image width*/);
		pos.y = SCREEN_H
		break;
	case FACING_RIGHT:
		pos.x
		pos.y
		break;
	case FACING_DOWN:
		pos.x = randomNumber(0, SCREEN_W - SAFETY_MARGIN);
		pos.y
		break;
	case FACING_LEFT:
		pos.x
		pos.y
		break;
	}
	 = 
	 = 
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
void Game::checkRotate(Ship *playerShip)
{
	//ROTATION (NEEDS WORK)
	if (key[KEY_Q])
	{
		rotate4(false,playerShip);
		//rotate left
	}
	if (key[KEY_E])
	{
		rotate4(true,playerShip);
		//rotate right
	}
	

}

void Game::checkFire(Ship *playerShip, std::vector<Bullet*> &bullets)
{
	if (key[KEY_SPACE])
	{
		bullets.push_back(new Bullet(playerShip->getTurretX(), playerShip->getTurretY(),
			playerShip->getDirection(),1));
		score -= 10;
	}
	
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
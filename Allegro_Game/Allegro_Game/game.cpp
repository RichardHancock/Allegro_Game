#include <allegro.h>
#include <string>
#include <vector>
#include <time.h>

#include "Game.h"
#include "Entity.h"
#include "Bullet.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "GameOverScreen.h"

extern volatile int timer; //Access timer from main 

Game::Game()
{
	score = 0; //Set base Score
}


int Game::run()
{

	srand(time(NULL));

	// LOAD RESOURCES:
	BITMAP* bg = load_bitmap("gameBackground.bmp",NULL);
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
	SAMPLE* laser = load_sample("laser1.wav");
	FONT* mainFont = load_font("myanmarFont.pcx",NULL,NULL);


	//LOAD GAME OBJECTS:
	//Creates the player ship object and spawns it near the middle of the screen.
	Ship *playerShip = new Ship("ship.bmp",SCREEN_W / 2,SCREEN_H / 2,0,1,5);

	std::vector<EnemyShip*> enemyShips; // Created as a vector to allow for future versions to have multiple enemies
	std::vector<Bullet*> bullets; // Stores all bullets fired
	

	/* NOT USED IN FINAL GAME
	//Initializing Mines
	std::vector<Mine*> mines;
	// Spawns four mines in all four corners to make maneuvering difficult
	mines.push_back( new Mine("mine.bmp", 45, 45));
	mines.push_back( new Mine("mine.bmp", 45, SCREEN_H - 45));
	mines.push_back( new Mine("mine.bmp", SCREEN_W - 45, 45));
	mines.push_back( new Mine("mine.bmp", SCREEN_W - 45, SCREEN_H - 45));
	*/


	const int ALLEGRO_RIGHT_ANGLE = 256 / 4;
	
	/*Delay for rotation and shooting, without this delay they occur at a
	very fast rate not suitable for the game.*/
	bool canFire = true;
	bool canRotate = true;
	int delay = 0;

	//Game Statuses 
	const int IN_PROGRESS = 0; // Game hasn't ended
	const int USER_EXIT = 1; // User pressed escape
	const int WIN = 2;
	const int LOSE = 3;

	int gameStatus = IN_PROGRESS; // Initialize the status var
	int enemiesDestroyed = 0; // Set kill count to 0.

	//Spawn first enemy
	spawnEnemy(enemyShips, enemiesDestroyed); 

	//Start actual game loop
	while(gameStatus == IN_PROGRESS)
	{
		while(timer)
		{
			// LOGICAL OPERATIONS
			// Keyboard and Player Input Checks
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
					// If can fire has been set to false, it means a bullet was fired
					play_sample(laser,255,128,1000,0); //Play Laser sound
				}
			}
			
			// Update NPC objects positions
			for (int i = 0; i < bullets.size(); i++)
			{
				bullets[i]->update();
			}

			enemyShips[0]->update();


			//Collision Tests

			// Checks if ships hit a boundary
			checkBoundries(playerShip);
			checkBoundries(enemyShips[0]);
			
			// Checks if player crashed into enemy ship 
			if (collisionTest(playerShip,enemyShips[0]))
			{
				playerShip->hit(1); 
			}

			// Check for collision with enemy ship with all bullet
			for (int i = 0; i < bullets.size(); i++)
			{
				if (collisionTest(enemyShips[0],bullets[i]))
				{
					// If a collision occurred both objects take damage.
					enemyShips[0]->hit(1);
					bullets[i]->hit(1);
				}
			}
			

			//DRAW OPERATIONS

			//Draw Background
			draw_sprite(buffer, bg, 0, 0);

			//Draw ship objects, accounting for their direction and rotating their BITMAPs.
			rotate_sprite(buffer, playerShip->getSprite(),playerShip->getX(),playerShip->getY(), 
				itofix(playerShip->getDirection() * ALLEGRO_RIGHT_ANGLE));

			rotate_sprite(buffer,enemyShips[0]->getSprite(),enemyShips[0]->getX(),enemyShips[0]->getY(),
				itofix(enemyShips[0]->getDirection() * ALLEGRO_RIGHT_ANGLE));

			//Draw all the bullets
			for (int i = 0; i < bullets.size(); i++)
			{
				circle(buffer, bullets[i]->getX(), bullets[i]->getY(), 3, makecol(255,255,255));
			}

			// Draw the score last, so its always on top
			textprintf_right_ex(buffer, mainFont, SCREEN_W - 5, 0,
				makecol(255,255,255),-1, "Score: %i", score);
			

			// Output the buffer to the screen
			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);


			// End Game Checks

			if(key[KEY_ESC]) {
				gameStatus = USER_EXIT;
			}

			if(playerShip->isDestroyed())
			{
				// if player dies, end game with lose scenario
				gameStatus = LOSE;
			}

			if (enemyShips[0]->isDestroyed())
			{
				//If the ship has been destroyed delete it and increment enemiesDestroyed count

				enemyShips.erase(enemyShips.begin());
				enemiesDestroyed++;
				gameStatus = spawnEnemy(enemyShips, enemiesDestroyed); /*Spawns new enemy and/or
				returns whether the game should continue or has been won */

				score += 10; // Award player points for ship destruction

				bullets.clear(); // Destroy all bullets, to avoid lucky shots on new enemies.
			}


			//Timer and Delay iterations 
			timer--;
			delay++;
		}
		
		// if delay has expired allow rotation and firing again.
		if (delay > 30) 
		{
			canFire = true;
			canRotate = true;
			delay = 0;
		}
	}
	
	//Destroy resources
	destroy_bitmap(bg);
	destroy_bitmap(buffer);
	destroy_sample(laser);
	destroy_font(mainFont);

	// Load Game Over Screen if the game ended with a win or lose, not a user exit.
	if (gameStatus != USER_EXIT)
	{
		GameOverScreen *gameOver; // create a empty pointer for the game over object.

		// Pass the results to game over screen so that it can display appropriate message.
		if (gameStatus == WIN)
		{
			gameOver = new GameOverScreen(true,score);
		}
		else
		{
			gameOver = new GameOverScreen(false,score);
		}

		gameOver->run(); // run the newly created game over screen
		delete gameOver; // Clear memory
	}

	return 0; // Return to menu
}



//Player Input Functions
void Game::checkKeyboard(Ship *playerShip)
{
	if (key[KEY_W] || key[KEY_UP])
	{
		playerShip->movePos('U');
	}
	if (key[KEY_S] || key[KEY_DOWN])
	{
		playerShip->movePos('D');
	}

	if (key[KEY_A] || key[KEY_LEFT])
	{
		playerShip->movePos('L');
	}
	if (key[KEY_D] || key[KEY_RIGHT])
	{
		playerShip->movePos('R');
	}

}

bool Game::checkRotate(Ship *playerShip)
{
	/* Checks if key pressed and sends a clockwise or anti-clockwise parameter
	to the rotate function*/
	
	if (key[KEY_Q])
	{
		//rotate left
		rotate4(false,playerShip);
		return false; // player rotated, start delay
	}
	if (key[KEY_E])
	{
		//rotate right
		rotate4(true,playerShip);
		return false; // player rotated, start delay
	}
	
	return true; // player didn't rotate, don't start delay
}

bool Game::checkFire(Ship *playerShip, std::vector<Bullet*> &bullets)
{
	if (key[KEY_SPACE])
	{
		//remove oldest bullet after 7 other bullets are in memory
		if (bullets.size() > 7){
			bullets.erase(bullets.begin());
		}

		// add new bullet to end of vector
		bullets.push_back(new Bullet(playerShip->getTurretX(), playerShip->getTurretY(),
			playerShip->getDirection(),1, 6));

		//Player loses a point, this is to try and deter bullet 'spamming'
		score -= 1;
		return false; //player fired so activate a delay
	}
	
	return true; //player didn't fire so do not activate a delay
}


//Collision Functions

void Game::checkBoundries(Ship* shipObject)
{
	//Fetch the 4 corners of the ship
	std::vector<Game::xyPos> shipPoints;
	shipPoints.resize(4);
	getFourCorners(shipObject, shipPoints);

	
	if (shipPoints[2].y < 0) // Check to see if it has gone past a boundary
	{
		shipObject->teleport(shipObject->getX(),SCREEN_H - 1); //Teleport it opposite side of screen
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

bool Game::collisionTest(Entity *object1, Entity *object2)
{
	//Created a vector array to store the coordinates of the objects.
	std::vector< std::vector<Game::xyPos> > objVec; //Multi dimensional vector 
	objVec.resize(2);
	objVec[0].resize(4);
	objVec[1].resize(4);

	// Get the coordinates for both objects
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
			return true; // collision occurred
		}

	}

	return false; // collision did not occur
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


// Misc Functions

int Game::randomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Game::rotate4(bool clockwise, Ship *playerShip)
{
	/* Checks to see if the intended rotation will be over the 0-3 direction limit
	if so it manually sets it to the opposite end of the scale.*/
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

int Game::spawnEnemy(std::vector<EnemyShip*> &enemyShips, int enemiesDestroyed)
{
	const int FACING_UP = 0;
	const int FACING_RIGHT = 1;
	const int FACING_DOWN = 2;
	const int FACING_LEFT= 3;

	//End game check
	if (enemiesDestroyed >= 5)
	{
		return 2; //returns a win status to the game loop
	}

	//Spawns a new ship off screen
	enemyShips.push_back(new EnemyShip("enemyShip.bmp",641,481,0,5,5));

	// Assign a random direction for the ship to spawn from
	int direction = randomNumber(0,3);

	//Create temp vars to minimize amount of calls and length of code
	xyPos pos;
	int width = enemyShips[0]->getWidth();
	int height = enemyShips[0]->getHeight();

	// Based on the random direction, set x & y to just off screen in a random position
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

	// Apply the newly generated rotation and position to the actual object
	enemyShips[0]->setDirection(direction);
	enemyShips[0]->teleport(pos.x,pos.y);

	return 0; //Game should continue so returns 0
}
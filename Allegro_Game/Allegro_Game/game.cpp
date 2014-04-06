#include <allegro.h>
#include <string>
#include <vector>
#include "Game.h"
#include "entity.h"
#include "Bullet.h"
#include "Ship.h"
#include "mine.h"

extern int timer;

Game::Game()
{
	
}

int Game::run()
{
	Ship *playerShip = new Ship("ship.bmp",SCREEN_W / 2,SCREEN_H / 2,100,2,1);
	
	buffer = create_bitmap(SCREEN_W,SCREEN_H);

	while(!key[KEY_ESC])
	{
		while(timer)
		{
			checkKeyboard(playerShip);
			checkRotate(playerShip);
			checkFire(playerShip);

			rotate_sprite(buffer, playerShip->getSprite(),playerShip->getX(),playerShip->getY(), 
				itofix(playerShip->getDirection() * 64));

			// draw collision bounding box
			rect(buffer, playerShip->getX(), playerShip->getY(), playerShip->getX() + playerShip->getSprite()->w,
				playerShip->getY()+playerShip->getSprite()->h, makecol(255,255,255));

			//draw_sprite(buffer, mines->getSprite(), mines->getX(),mines->getY());

			/*for (int i = 0; i < bullets.size(); i++)
			{
				circle(buffer, bullets[i].getX(), bullets[i].getY(), 3, makecol(255,255,255));
			}*/

			
			
			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--;
		}
	}

	destroy_bitmap(buffer);
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
		//rotate_sprite(buffer, playerShip, ship_x, ship_y, 256 / direction); //BROKEN (divide by 0)
	}
}

void Game::checkFire(Ship *playerShip)
{
	if (key[KEY_SPACE])
	{
		//Fire
		/*bullets.push_back(Bullet(playerShip->getTurretX(), playerShip->getTurretY(),
			playerShip->getDirection(),1));
		score -= 10;*/
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

void Game::update()
{
	/*
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update();
	}
	*/
}
#include <allegro.h>
#include <vector>
#include <string>
#include "entity.h"
#include "Bullet.h"
#include "Ship.h"
#include "mine.h"
#include "Game.h"

/*BITMAP *buffer;
BITMAP *enemyShip;
BITMAP *bullet;
Ship *playerShip;
Mine *mines;*/
void rotate4(bool, BITMAP*, BITMAP*);
//void rotate8(bool, BITMAP*, BITMAP*); old rotate
void checkKeyboard();
void checkFire();
void checkRotate();
void update();
/*void score(int);
int score();*/
void timer_increment();

int timer = 0;
int scoreVar = 0;
std::vector<Bullet> bullets;

int main()
{
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();

	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
	/*playerShip = new Ship("ship.bmp",SCREEN_W / 2,SCREEN_H / 2,100,2,1);
	mines = new Mine("mine.bmp",20,20);
	buffer = create_bitmap(SCREEN_W,SCREEN_H);*/

	install_int_ex(timer_increment, BPS_TO_TIMER(100)); //REFERENCE THIS

	/*install_int(checkKeyboard, 10);
	install_int(checkFire, 300);
	install_int(checkRotate, 100);
	install_int(update, 10);*/

	while (!key[KEY_ESC])
	{

		//Menu here
		Game *mainGameLoop = new Game(); //Create the Game class object
		mainGameLoop->run(); //Start the Game loop
		
		/* OLD LOOP
		rotate_sprite(buffer, playerShip->getSprite(),playerShip->getX(),playerShip->getY(), 
			itofix(playerShip->getDirection() * 64));
		
		// draw collision bounding box
		rect(buffer, playerShip->getX(), playerShip->getY(), playerShip->getX() + playerShip->getSprite()->w,
			playerShip->getY()+playerShip->getSprite()->h, makecol(255,255,255));
		
		draw_sprite(buffer, mines->getSprite(), mines->getX(),mines->getY());

		for (int i = 0; i < bullets.size(); i++)
		{
			circle(buffer, bullets[i].getX(), bullets[i].getY(), 3, makecol(255,255,255));
		}
		
		//OLDmasked_blit(*playerShip, buffer, 0, 0, ship_x, ship_y, *playerShip->w, *playerShip->h);

		blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
		clear_bitmap(buffer);
		*/

	}
	/*
	destroy_bitmap(buffer);
	destroy_bitmap(enemyShip);
	destroy_bitmap(bullet);
	*/
	return 0;
}
END_OF_MAIN();

void timer_increment()
{
	timer++;
}
/*
void rotate4(bool clockwise, BITMAP * src, BITMAP * dest)
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

void rotate8(bool clockwise, BITMAP * src, BITMAP * dest)
{

	//divide the total number of directions by the max rotation (256) and then
	//either plus or minus the amount to rotate
	//rotateDegrees = 0;

	if (clockwise)
	{
		if (playerShip->getDirection() == 7)
		{
			playerShip->setDirection(0);
		}
		else
		{
			playerShip->setDirection(true);
		}
		//rotateDegrees = 256 - (32 * playerShip->getDirection());
	}
	else
	{
		if (playerShip->getDirection() == 0)
		{
			playerShip->setDirection(7);
		}
		else
		{
			playerShip->setDirection(false);
		}
		//rotateDegrees = 256 - (ROTATE_CALC * playerShip->getDirection());
		//rotateDegrees = -rotateDegrees;
	}

	
}

void score(int pointsToAdd)
{
	scoreVar += pointsToAdd;
}
int score()
{
	return scoreVar;
}

void checkKeyboard()
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
void checkRotate()
{
	//ROTATION (NEEDS WORK)
	if (key[KEY_Q])
	{
		rotate4(false,playerShip->getSprite(),buffer);
		//rotate left
	}
	if (key[KEY_E])
	{
		rotate4(true,playerShip->getSprite(),buffer);
		//rotate right
		//rotate_sprite(buffer, playerShip, ship_x, ship_y, 256 / direction); //BROKEN (divide by 0)
	}
}

void checkFire()
{
	if (key[KEY_SPACE])
	{
		//Fire
		bullets.push_back(Bullet(playerShip->getTurretX(), playerShip->getTurretY(),
			playerShip->getDirection(),1));
		scoreVar -= 10;
	}
}
*/

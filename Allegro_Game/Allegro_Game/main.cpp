#include <allegro.h>
#include <vector>
#include <string>
#include "entity.h"
#include "Bullet.h"
#include "Ship.h"



//helpful Web http://www.cs.bu.edu/teaching/cpp/inheritance/intro/

BITMAP *buffer;
BITMAP *enemyShip;
BITMAP *bullet;
Ship *playerShip;// = Ship("playerShip.bmp",10 / 2,10 / 2,100,10,1);
void rotate(Entity, bool, BITMAP*, BITMAP* );
void checkKeyboard();
void checkFire();
void update();
void score(int);
int score();

const int ROTATE_CALC = 256 / 8; // maximum number of degrees divided by number of directions

int speed = 2;
int scoreVar = 0;
//int ship_x = 0;
//int ship_y = 0;
//int direction = 0;
//int ship_x = 0;
//int ship_y = 0;

std::vector<Bullet> bullets;

int main()
{
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();

	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
	*playerShip = Ship("playerShip.bmp",10 / 2,10 / 2,100,10,1);
	//ship_x = SCREEN_W / 2;
	//ship_y = SCREEN_H / 2;

	//*playerShip = load_bitmap("*playerShip.bmp", NULL);
	buffer = create_bitmap(SCREEN_W,SCREEN_H);

	install_int(checkKeyboard, 10);
	install_int(checkFire, 300);
	install_int(update, 100);

	while (!key[KEY_ESC])
	{
		//*playerShip = Ship("*playerShip.bmp",SCREEN_W / 2,SCREEN_H / 2,100,10,1);

		clear_to_color(buffer, makecol(0,0,0));

		//rotate_sprite(buffer, &*playerShip.getSprite(),*playerShip.getX(),*playerShip.getY(),*playerShip.getDirection());
		draw_sprite(buffer, playerShip.getSprite(), *playerShip.getX(), *playerShip.getY());
		// draw collision bounding box
		rect(buffer, *playerShip.getX(), *playerShip.getY(), *playerShip.getX() + *playerShip.getSprite()->w,
			*playerShip.getY()+*playerShip.getSprite()->h, makecol(255,255,255));
		
		for (int i = 0; i < bullets.size(); i++)
		{
			circle(buffer, bullets[i].getX(), bullets[i].getY(), 3, makecol(255,255,255));
		}
		
		//OLDmasked_blit(*playerShip, buffer, 0, 0, ship_x, ship_y, *playerShip->w, *playerShip->h);

		blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
		clear_bitmap(buffer);

	}
	
	destroy_bitmap(buffer);
	destroy_bitmap(enemyShip);
	destroy_bitmap(bullet);

	return 0;
}
END_OF_MAIN();

void rotate(Entity object, bool clockwise, BITMAP &src, BITMAP &dest)
{

	//divide the total number of directions by the max rotation (256) and then
	//either plus or minus the amount to rotate
	int rotateDegrees = 0;

	if (clockwise)
	{
		if (object.getDirection() == 7)
		{
			object.setDirection(0);
		}
		else
		{
			object.setDirection(true);
		}
		rotateDegrees = 256 - (ROTATE_CALC * object.getDirection());
	}
	else
	{
		if (object.getDirection() == 0)
		{
			object.setDirection(7);
		}
		else
		{
			object.setDirection(false);
		}
		rotateDegrees = 256 - (ROTATE_CALC * object.getDirection());
		rotateDegrees = -rotateDegrees;
	}

	rotate_sprite(&dest, &src,NULL,NULL, rotateDegrees);
}

void score(int pointsToAdd)
{
	scoreVar += pointsToAdd;
}
int score()
{
	return scoreVar;
}

void checkKeyboard(Ship &playerShip)
{
	if (key[KEY_W] || key[KEY_UP])
	{
		//ship_y -= speed;
		playerShip.movePos(0,-speed);
	}
	if (key[KEY_S] || key[KEY_DOWN])
	{
		//ship_y += speed;
		playerShip.movePos(0,speed);
	}
	if (key[KEY_A] || key[KEY_LEFT])
	{
		//ship_x -= speed;
		playerShip.movePos(-speed,0);
	}
	if (key[KEY_D] || key[KEY_RIGHT])
	{
		//ship_x += speed;
		playerShip.movePos(speed,0);
	}

	//ROTATION (NEEDS WORK)
	if (key[KEY_Q])
	{
		
		//rotate left
	}
	if (key[KEY_E])
	{
		
		//rotate right
		//rotate_sprite(buffer, playerShip, ship_x, ship_y, 256 / direction); //BROKEN (divide by 0)
	}
}

void checkFire()
{
	if (key[KEY_SPACE])
	{
		//Fire
		bullets.push_back(Bullet(playerShip.getX() + *playerShip.getSprite()->w / 2, *playerShip.getY(), 0/*TEMP*/,1));
	}
}

void update()
{
	
}
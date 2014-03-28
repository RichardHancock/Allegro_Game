#include <allegro.h>
#include <vector>
#include "bullet.h"

BITMAP *buffer;
BITMAP *playerShip;
BITMAP *enemyShip;
BITMAP *bullet;

void checkKeyboard();
void checkFire();
void update();
void score(int);
int score();

int speed = 2;
int scoreVar = 0;
int ship_x = 0;
int ship_y = 0;
int direction = 0;
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

	ship_x = SCREEN_W / 2;
	ship_y = SCREEN_H / 2;

	playerShip = load_bitmap("playership.bmp", NULL);
	buffer = create_bitmap(SCREEN_W,SCREEN_H);

	install_int(checkKeyboard, 10);
	install_int(checkFire, 300);
	install_int(update, 100);

	while (!key[KEY_ESC])
	{
		clear_to_color(buffer, makecol(0,0,0));


		rotate_sprite(buffer, playerShip,ship_x,ship_y,direction);
		draw_sprite(buffer, playerShip, ship_x, ship_y);
		// draw collision bounding box
		rect(buffer, ship_x, ship_y, ship_x+playerShip->w, ship_y+playerShip->h, makecol(255,255,255));
		
		for (int i = 0; i < bullets.size(); i++)
		{
			circle(buffer, bullets[i].getX(), bullets[i].getY(), 3, makecol(255,255,255));
		}
		
		//OLDmasked_blit(playerShip, buffer, 0, 0, ship_x, ship_y, playerShip->w, playerShip->h);

		blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
		clear_bitmap(buffer);

	}
	
	destroy_bitmap(buffer);
	destroy_bitmap(playerShip);
	destroy_bitmap(enemyShip);
	destroy_bitmap(bullet);

	return 0;
}
END_OF_MAIN();

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
		ship_y -= speed;
	}
	if (key[KEY_S] || key[KEY_DOWN])
	{
		ship_y += speed;
	}
	if (key[KEY_A] || key[KEY_LEFT])
	{
		ship_x -= speed;
	}
	if (key[KEY_D] || key[KEY_RIGHT])
	{
		ship_x += speed;
	}
	if (key[KEY_Q])
	{
		direction -= 1;
		if (direction < 0) {
			direction = 256;
		}
		//rotate left
	}
	if (key[KEY_E])
	{
		direction += 1;
		if (direction > 256) {
			direction = 0;
		}
		//rotate right
	}
}

void checkFire()
{
	if (key[KEY_SPACE])
	{
		//Fire
		bullets.push_back(Bullet(ship_x + playerShip->w / 2,ship_y));
	}
}

void update()
{
	
}
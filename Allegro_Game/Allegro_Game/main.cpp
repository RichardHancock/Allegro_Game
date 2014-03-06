#include <allegro.h>

BITMAP *buffer;
BITMAP *playerShip;
BITMAP *enemyShip;
BITMAP *bullet;

int score = 0;

int main()
{
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();

	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

	buffer = create_bitmap(SCREEN_W,SCREEN_H);


	
	destroy_bitmap(buffer);
	destroy_bitmap(playerShip);
	destroy_bitmap(enemyShip);
	destroy_bitmap(bullet);

	return 0;
}
END_OF_MAIN();
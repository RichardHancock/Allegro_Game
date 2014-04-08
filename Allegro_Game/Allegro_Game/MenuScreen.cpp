#include <vector>
#include <allegro.h>
#include "MenuScreen.h"

extern volatile int timer;

int MenuScreen::run()
{
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* bg = load_bitmap("menuBackground.bmp",NULL);
	BITMAP* logo = load_bitmap("logo.bmp",NULL);
	show_os_cursor(MOUSE_CURSOR_ARROW);

	std::vector< std::vector<BITMAP*> > buttons;
	buttons.resize(2);
	buttons[0].resize(4);
	buttons[1].resize(4);
	
	buttons[0][0] = load_bitmap("button1.bmp",NULL);
	buttons[0][1] = load_bitmap("button2.bmp",NULL);
	buttons[0][2] = load_bitmap("button3.bmp",NULL);
	buttons[0][3] = load_bitmap("button4.bmp",NULL);

	buttons[1][0] = load_bitmap("button1Hover.bmp",NULL);
	buttons[1][1] = load_bitmap("button2Hover.bmp",NULL);
	buttons[1][2] = load_bitmap("button3Hover.bmp",NULL);
	buttons[1][3] = load_bitmap("button4Hover.bmp",NULL);

	int thirdOfScreen = SCREEN_W / 3;

	bool endMenu = false;

	while(!endMenu)
	{
		while(timer)
		{

			draw_sprite(buffer, bg, 0, 0);

			draw_sprite(buffer,logo,96,20);

			if (mouse_y > 150 && mouse_y < 200 && mouse_x > 220 && mouse_x < 420)
			{
				draw_sprite(buffer, buttons[1][0], 220, 150);
				if (mouse_b & 1)
				{
					return 1;
				}
			}
			else
			{
				draw_sprite(buffer, buttons[0][0], 220, 150);
			}

			if (mouse_y > 225 && mouse_y < 275 && mouse_x > 220 && mouse_x < 420)
			{
				draw_sprite(buffer, buttons[1][1], 220, 225);
				if (mouse_b & 1)
				{
					return 2;
				}
			}
			else
			{
				draw_sprite(buffer, buttons[0][1], 220, 225);
			}

			if (mouse_y > 300 && mouse_y < 350 && mouse_x > 220 && mouse_x < 420)
			{
				draw_sprite(buffer, buttons[1][2], 220, 300);
				if (mouse_b & 1)
				{
					return 3;
				}
			}
			else
			{
				draw_sprite(buffer, buttons[0][2], 220, 300);
			}

			if (mouse_y > 375 && mouse_y < 425 && mouse_x > 220 && mouse_x < 420)
			{
				draw_sprite(buffer, buttons[1][3], 220, 375);
				if (mouse_b & 1)
				{
					return 0;
				}
			}
			else
			{
				draw_sprite(buffer, buttons[0][3], 220, 375);
			}
		

			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--;
			//rect(buffer, thirdOfScreen, 200, thirdOfScreen * 2, 250,makecol(255,255,255));
			//if(mouse_x)
		}

	}

	// Destroy all menu bitmaps
	destroy_bitmap(bg);
	destroy_bitmap(logo);
	destroy_bitmap(buffer);
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			destroy_bitmap(buttons[i][j]);
		}
	}

}
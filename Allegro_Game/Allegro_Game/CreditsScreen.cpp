#include <allegro.h>
#include "CreditsScreen.h"

extern volatile int timer; //Global timer between files, as Allegro only allows timers in main

int CreditsScreen::run()
{
	// LOAD RESOURCES:
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* bg = load_bitmap("menuBackground.bmp",NULL);
	BITMAP* logo = load_bitmap("logo.bmp",NULL);
	FONT* mainFont = load_font("myanmarFont.pcx",NULL,NULL);

	bool exitScreen = false;

	while(!exitScreen)
	{
		while(timer)
		{
			// Draw the background assets
			draw_sprite(buffer, bg, 0, 0);
			draw_sprite(buffer,logo,96,20);
			rectfill(buffer,96, 150, 544, 400, makecol(2,2,2));

			//This section could be written as a loop that takes text from a text file line by line.
			textout_centre_ex(buffer, mainFont, "IMAGES:", SCREEN_W / 2, 160,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Ship - Rawdanitsu", SCREEN_W / 2, 180,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Backgrounds - Rawdanitsu", SCREEN_W / 2, 200,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "SOUND:", SCREEN_W / 2, 240,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Laser - dklon", SCREEN_W / 2, 260,
				makecol(255,255,255),-1);

			textout_centre_ex(buffer, mainFont, "Press Escape Key to return to the Menu", SCREEN_W / 2, 380,
				makecol(255,255,255),-1);

			if (key[KEY_ESC])
			{
				//End the loop so the function will return control back to main
				exitScreen = true;
			}

			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--; //Decrement the global timer

		}
	}

	// DESTROY RESOURCES:
	destroy_bitmap(bg);
	destroy_bitmap(logo);
	destroy_bitmap(buffer);
	destroy_font(mainFont);

	// return to menu.
	return 0;


}
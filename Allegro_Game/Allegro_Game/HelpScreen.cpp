
#include <allegro.h>
#include "HelpScreen.h"

extern volatile int timer; //Global timer between files, as Allegro only allows timers in main

int HelpScreen::run()
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
			rectfill(buffer,96, 150, 544, 460, makecol(2,2,2));

			//This section could be written as a loop that takes text from a text file line by line.
			textout_centre_ex(buffer, mainFont, "CONTROLS:", SCREEN_W / 2, 160,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Forward - W / UP", SCREEN_W / 2, 180,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Backward - S / DOWN", SCREEN_W / 2, 200,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Strafe Left - A / LEFT", SCREEN_W / 2, 220,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Strafe Right - D / RIGHT", SCREEN_W / 2, 240,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Rotate Left - Q", SCREEN_W / 2, 260,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Rotate Right - E", SCREEN_W / 2, 280,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Fire - SPACE", SCREEN_W / 2, 300,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Main Menu - ESCAPE", SCREEN_W / 2, 320,
				makecol(255,255,255),-1);

			textout_centre_ex(buffer, mainFont, "GOAL:", SCREEN_W / 2, 340,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "Destroy the enemy five times, while avoiding", SCREEN_W / 2, 360,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "mines and ships. Use bullets carefully as you", SCREEN_W / 2, 380,
				makecol(255,255,255),-1);
			textout_centre_ex(buffer, mainFont, "lose points for every shot.", SCREEN_W / 2, 400,
				makecol(255,255,255),-1);

			textout_centre_ex(buffer, mainFont, "Press Escape Key to return to the Menu", SCREEN_W / 2, 430,
				makecol(255,255,255),-1);


			if (key[KEY_ESC])
			{
				//End the loop so the function will return control back to main
				exitScreen = true;
			}

			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--;
			
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
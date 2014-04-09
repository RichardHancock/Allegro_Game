#include <allegro.h>
#include "GameOverScreen.h"

extern volatile int timer;

GameOverScreen::GameOverScreen(bool isVictoryInput,int score)
{
	finalScore = score;

	// This variable holds the Win/Lose state of the game.
	isVictory = isVictoryInput;
	// Without it, two GameOverScreen classes would be required
}

int GameOverScreen::run()
{
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* bg = load_bitmap("menuBackground.bmp",NULL);
	BITMAP* logo = load_bitmap("logo.bmp",NULL);
	FONT* mainFont = load_font("myanmarFont.pcx",NULL,NULL);

	bool exitScreen = false;

	while(!exitScreen)
	{
		while(timer)
		{

			draw_sprite(buffer, bg, 0, 0);

			draw_sprite(buffer,logo,96,20);

			rectfill(buffer,96, 150, 544, 400, makecol(2,2,2));

			if (isVictory) {
				textout_centre_ex(buffer, mainFont, "You Win!", SCREEN_W / 2, 220,
					makecol(255,255,255),makecol(2,2,2));
				
			}
			else
			{
				textout_centre_ex(buffer, mainFont, "You Lose!", SCREEN_W / 2, 220,
					makecol(255,255,255),makecol(2,2,2));
			}

			textprintf_centre_ex(buffer, mainFont, SCREEN_W / 2, 260,
				makecol(255,255,255),makecol(2,2,2), "Your Score: %i", finalScore);

			textout_centre_ex(buffer, mainFont, "Press Escape Key to return to the Menu", SCREEN_W / 2, 340,
				makecol(255,255,255),makecol(2,2,2));

			if (key[KEY_ESC])
			{
				exitScreen = true;
			}

			blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			clear_bitmap(buffer);

			timer--;

		}
	}

	// Destroy all menu bitmaps
	destroy_bitmap(bg);
	destroy_bitmap(logo);
	destroy_bitmap(buffer);
	destroy_font(mainFont);


	// return to menu.
	return 0;


}
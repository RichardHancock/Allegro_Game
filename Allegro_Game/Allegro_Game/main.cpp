#include <allegro.h>
#include "Game.h"
#include "MenuScreen.h"
#include "HelpScreen.h"
#include "CreditsScreen.h"

void timer_increment(); //Increment the global timer
void runGame();
void runHelp();
void runCredits();

volatile int timer = 0; //Global Timer, used because Allegro won't allow timers in classes or allow function arguments in timer calls.

void timer_increment()
{
	timer++;
}

void runGame()
{
	Game *mainGameLoop = new Game(); //Create the Game class object
	mainGameLoop->run(); //Start the Game loop

	delete mainGameLoop; //Clean Up memory
}
void runHelp()
{
	HelpScreen *helpScreen = new HelpScreen(); //Create the HelpScreen class object
	helpScreen->run(); //Start loop

	delete helpScreen; //Clean Up memory
}
void runCredits()
{
	CreditsScreen *creditsScreen = new CreditsScreen(); //Create the CreditsScreen class object
	creditsScreen->run(); //Start loop

	delete creditsScreen; //Clean Up memory
}


int main()
{
	//Required Allegro init functions
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
	set_window_title("Star Fire");
	show_os_cursor(MOUSE_CURSOR_ARROW);

	//Start repeating timer
	install_int_ex(timer_increment, BPS_TO_TIMER(60)); 
	/* Sets how many ticks occur in a second, in this case I use 60, which should run the game at around
	60FPS on most computers*/


	while (true) //Infinite until return statement
	{
		MenuScreen *menuLoop = new MenuScreen(); //Create the menu object

		int menuResult = menuLoop->run(); // run the menu and store the result
		delete menuLoop; // Delete for Performance

		//Test the result to find out what action should be performed.
		switch (menuResult)
		{
		case 0:
			// Exit
			return 0;
			break;
		case 1:
			// Play / Game
			runGame();
			break;
		case 2:
			// Help
			runHelp();
			break;
		case 3:
			// Credits
			runCredits();
			break;
		}

		//If an exit hasn't been requested, the game will restart the menu.
	}
}
END_OF_MAIN();

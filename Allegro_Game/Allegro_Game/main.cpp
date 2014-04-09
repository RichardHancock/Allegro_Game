#include <allegro.h>
#include "Game.h"
#include "MenuScreen.h"
#include "HelpScreen.h"
#include "CreditsScreen.h"

/*Mine *mines;
void score(int);
int score();*/
void timer_increment();
void runGame();
void runHelp();
void runCredits();

volatile int timer = 0;

void timer_increment()
{
	timer++;
}

void runGame()
{
	Game *mainGameLoop = new Game(); //Create the Game class object
	mainGameLoop->run(); //Start the Game loop

	delete mainGameLoop;
}
void runHelp()
{
	HelpScreen *helpScreen = new HelpScreen(); //Create the HelpScreen class object
	helpScreen->run(); //Start loop

	delete helpScreen;
}
void runCredits()
{
	CreditsScreen *creditsScreen = new CreditsScreen(); //Create the CreditsScreen class object
	creditsScreen->run(); //Start loop

	delete creditsScreen;
}


int main()
{
	//Required Allegro init functions
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
	set_window_title("Star Fire");


	//Start repeating timer
	install_int_ex(timer_increment, BPS_TO_TIMER(60)); //REFERENCE THIS
	

	while (true) //Infinite until return statement
	{
		MenuScreen *menuLoop = new MenuScreen();

		int menuResult = menuLoop->run();
		delete menuLoop; // Delete for Performance

		switch (menuResult)
		{
		// Exit
		case 0:
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



/*
void score(int pointsToAdd)
{
	scoreVar += pointsToAdd;
}
int score()
{
	return scoreVar;
}
*/

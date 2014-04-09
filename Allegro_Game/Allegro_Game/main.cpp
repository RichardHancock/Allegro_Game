#include <allegro.h>
#include "Game.h"
#include "MenuScreen.h"


/*Mine *mines;
void score(int);
int score();*/
void timer_increment();

volatile int timer = 0;
//std::vector<Bullet> bullets;

void timer_increment()
{
	timer++;
}

int main()
{
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();

	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
	
	//mines = new Mine("mine.bmp",20,20);

	install_int_ex(timer_increment, BPS_TO_TIMER(60)); //REFERENCE THIS
	set_window_title("Star Fire");

	bool gameEnd = false;

	while (!gameEnd)
	{

		MenuScreen *menuLoop = new MenuScreen();
		Game *mainGameLoop = new Game(); //Create the Game class object
		//this is created here, as switch statements do not allow the creation of objects within them.

		int menuResult = menuLoop->run();

		switch (menuResult)
		{
		//Exit
		case 0:
			gameEnd = true;

			break;
		case 1:
			mainGameLoop->run(); //Start the Game loop and store return state
			
			break;
		case 2:
			//Credits
			break;
		}

		

		//Delete both objects
		delete mainGameLoop;
		delete menuLoop;

		//If an exit hasn't been requested, the game will restart at menu.
	}
	
	return 0;
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

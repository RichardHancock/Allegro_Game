#pragma once
#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class GameOverScreen : public ScreenState
{
private:
	int finalScore; // holds the final score from the game
	bool isVictory; // This variable holds the Win/Lose state of the game.

public:
	GameOverScreen(bool,int); 

	virtual int run(); //Redefines pure virtual function of parent
};

#endif
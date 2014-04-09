#pragma once
#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class GameOverScreen : public ScreenState
{
private:
	int finalScore; // This variable holds the Win/Lose state of the game.
	bool isVictory;
public:
	GameOverScreen(bool,int);
	virtual int run();
};

#endif
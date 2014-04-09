#pragma once
#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class GameOverScreen : public ScreenState
{
private:

public:
	GameOverScreen(bool);
	virtual int run();
};

#endif
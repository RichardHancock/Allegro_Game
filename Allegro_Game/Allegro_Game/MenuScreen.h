#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class MenuScreen : public ScreenState
{
public:
	virtual int run(); 
};

#endif
#pragma once
#ifndef SCREENSTATE_H
#define SCREENSTATE_H


#include <allegro.h>

class ScreenState
{
	//Abstract Base Class inherited by every Screen/Menu (Game,Menu,Help,Credits)

public:
	virtual int run() = 0; //Pure virtual function that is redefined in all sub (child) classes.
	
};


#endif
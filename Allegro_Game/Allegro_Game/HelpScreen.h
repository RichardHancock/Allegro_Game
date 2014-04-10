#pragma once
#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class HelpScreen : public ScreenState
{
public:
	virtual int run(); //Redefines pure virtual function of parent
};

#endif
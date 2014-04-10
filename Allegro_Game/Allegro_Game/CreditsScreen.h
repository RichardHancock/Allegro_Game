#pragma once
#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class CreditsScreen : public ScreenState
{
public:
	virtual int run(); //Redefines pure virtual function of parent
};

#endif
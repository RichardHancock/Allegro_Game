#pragma once
#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include <allegro.h>
#include "ScreenState.h"

class CreditsScreen : public ScreenState
{
private:

public:
	virtual int run();
};

#endif
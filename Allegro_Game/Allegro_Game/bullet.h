#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <allegro.h>

class Bullet
{
private:
	int x;
	int y;
public:
	Bullet(int, int);
	void movePos(int, int);
	int getX();
	int getY();
};

#endif
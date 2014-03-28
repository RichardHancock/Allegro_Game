#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <allegro.h>

class Bullet
{
private:
	int x;
	int y;
	int direction;
public:
	Bullet(int, int, int);
	void movePos(int, int);
	void rotate(int);
	int getX();
	int getY();
};

#endif
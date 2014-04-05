#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "entity.h"
#include <allegro.h>

class Bullet : public Entity
{
private:
	//int x;
	//int y;
	//int direction;
	int speed;
public:
	Bullet(int, int, int, int);
	void update();
	/*void movePos(int, int);
	//void rotate(int);
	//int getX();
	//int getY();*/
};

#endif
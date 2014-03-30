#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <allegro.h>

class Entity
{
protected:
	int x;
	int y;
	int direction;
	int health;
public:
	Entity(int,int,int,int);
	~Entity();
	int rotate(int);
	void movePos(int, int);
	int hit(int);
	int getHealth();
	int getDirection();
	int getX();
	int getY();
};

#endif
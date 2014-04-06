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
	virtual void setDirection(int);
	virtual void setDirection(bool);
	void movePos(int, int);
	//void movePos(char);
	int hit(int);
	int getHealth();
	int getDirection();
	int getX();
	int getY();
};

#endif
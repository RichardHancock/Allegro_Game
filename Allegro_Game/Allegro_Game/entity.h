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
	
	//Added for compatibility between non-sprite (bullets) and sprite objects
	int width;
	int height;
	bool isCircleVar;
public:
	Entity(int,int,int,int);
	~Entity();
	virtual void setDirection(int);
	virtual void setDirection(bool);
	void movePos(int, int);
	int hit(int);
	int getHealth();
	int getDirection();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	bool isCircle();
};

#endif
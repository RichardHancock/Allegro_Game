#pragma once
#ifndef SHIP_H
#define SHIP_H

#include "entity.h"
#include <allegro.h>
#include <string>

class Ship : public Entity
{
private:
	static const int FACING_UP = 0;
	static const int FACING_RIGHT = 1;
	static const int FACING_DOWN = 2;
	static const int FACING_LEFT= 3;

	int turretX;
	int turretY;
	int speed;
	BITMAP *sprite;
	short weaponType;
	void recalculateTurretPos();
public:
	Ship(std::string, int, int, int, int, short);

	~Ship();
	
	//void movePos(int, int);

	//int rotate(int);

	int getSpeed();

	//int hit(int);
	void movePos(char);
	BITMAP * getSprite();
	void setSprite(std::string path);
	
};
#endif
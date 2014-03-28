#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <allegro.h>
#include <string>

class Ship
{
private:
	int x;
	int y;
	int direction;
	int health;
	int speed;
	BITMAP *sprite;
	short weaponType;
public:
	Ship(std::string, int, int, int, int, short);
	~Ship();
	void movePos(int, int);
	int getSpeed();
	int hit(int);
	BITMAP getSprite();
	void setSprite(std::string path);
	
};
#endif
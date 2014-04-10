#pragma once
#ifndef SHIP_H
#define SHIP_H

#include "entity.h"
#include "spriteLoader.h"
#include <allegro.h>
#include <string>

class Ship : public Entity, public SpriteLoader //Multiple Inheritance
{
protected:
	// Direction constants used in direction/rotation functions for clarity
	static const int FACING_UP = 0;
	static const int FACING_RIGHT = 1;
	static const int FACING_DOWN = 2;
	static const int FACING_LEFT= 3;

	int speed;

	//Turret position (Where bullets spawn)
	int turretX;
	int turretY;
	void recalculateTurretPos(); //Called when ship moves or rotates, so bullets spawn correctly

public:
	Ship(std::string, int, int, int, int, int);
	
	// Mixed Getter Functions
	int getSpeed();
	int getTurretX();
	int getTurretY();

	// Redefinitions of functions in parent, mostly just to add a call to recalculateTurretPos().
	virtual void setDirection(int);// Set direction equal to parameter
	virtual void setDirection(bool); //if bool is true rotate clockwise 90 degrees (64 Allegro Degrees)
	//else rotate anti-clockwise

	void movePos(char); //Move in a direction accounting for direction accepts a char direction.
	//Letter direction means "U" = UP, "D" = DOWN etc.


	virtual void setSprite(std::string); //Differs from parent as width and height vars need to be set.
	
	
};
#endif
#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <allegro.h>

class Entity
{
	/*Entity base class
	An entity is any object that appears in the game
	It holds basic movement, rotation and health functions require by all other game objects.
	*/

protected:
	int x; // X position
	int y; // Y position
	int direction; // Stores 0-3 which signify what direction it is facing 
	int health; // Current health, mostly redundant as all Entity in the game have 1 health.
	//but having this option does allow for future expansion

	bool destroyed; // True if entity has been killed in game, false if not.

	//Following added for compatibility between non-sprite (bullets) and sprite objects
	int width;
	int height;
	bool isCircleVar;

public:
	Entity(int,int,int,int);

	//Movement functions
	void teleport(int,int); //Moves by setting the current X & Y position equal to the parameters

	//Rotation functions
	int getDirection();
	virtual void setDirection(int); // Set direction equal to parameter
	virtual void setDirection(bool); //if bool is true rotate clockwise 90 degrees (64 Allegro Degrees)
	//else rotate anti-clockwise
	
	//Mixed Getter functions
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	
	bool isCircle(); // Fix for when the x and y position are center aligned, rather than at top left.

	// Health functions
	int hit(int); // Take damage equivalent to parameter
	int getHealth(); 
	bool isDestroyed(); //Returns true if object is destroyed
	
};

#endif
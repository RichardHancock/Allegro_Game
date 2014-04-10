#include "entity.h"
#include <allegro.h>


Entity::Entity(int startX, int startY, int startRotation, int startHealth)
{
	x = startX;
	y = startY;
	direction = startRotation;
	health = startHealth;
	destroyed = false; // Default state, until destruction

	isCircleVar = false; //will be overridden when needed
}


// Movement functions
void Entity::teleport(int newX, int newY)
{
	x = newX;
	y = newY;
}


// Rotation functions
int Entity::getDirection()
{
	return direction;
}

void Entity::setDirection(int rotation)
{
	direction = rotation;
}

void Entity::setDirection(bool increment) //if true increment direction, if false take 1 away 
{
	// Basically means rotate clockwise or anti-clockwise
	if (increment)
	{
		direction++;
	} 
	else
	{
		direction--;
	}
}


//Mixed Getter Functions
int Entity::getX()
{
	return x;
}
int Entity::getY()
{
	return y;
}

int Entity::getWidth()
{
	return width;
}
int Entity::getHeight()
{
	return height;
}

bool Entity::isCircle()
{
	return isCircleVar;
}


// Health Functions
int Entity::hit(int damage)
{
	health -= damage;

	// Check if object is dead and set var accordingly
	if (health <= 0)
	{
		destroyed = true;
	}

	return health; //returns the health for possible future health bar addition.
}

int Entity::getHealth()
{
	return health;
}

bool Entity::isDestroyed()
{
	return destroyed;
}


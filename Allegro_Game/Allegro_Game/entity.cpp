#include "entity.h"
#include <allegro.h>


Entity::Entity(int startX, int startY, int startRotation, int startHealth)
{
	x = startX;
	y = startY;
	direction = startRotation;
	health = startHealth;
}
Entity::~Entity()
{

}

void Entity::setDirection(int rotation)
{
	direction = rotation;
}
void Entity::setDirection(bool increment) //if true increment direction, if false take 1 away 
{
	if (increment)
	{
		direction++;
	} 
	else
	{
		direction--;
	}
}

/*void Entity::movePos(int adjustX, int adjustY)
{
	x += adjustX;
	y += adjustY;
}*/
void Entity::movePos(int adjustX, int adjustY)
{
	switch(direction)
	{
	case 0:
		x += adjustX;
		y += adjustY;
		break;
	case 1:
		x += adjustY;
		y += adjustX;
		break;
	case 2:
		x -= adjustY;
		y += adjustX;
		break;
	case 3:
		x -= adjustX;
		y -= adjustY;
		break;
	}
}
int Entity::hit(int damage)
{
	health -= damage;

	return health;
}


int Entity::getHealth()
{
	return health;
}
int Entity::getDirection()
{
	return direction;
}
int Entity::getX()
{
	return x;
}
int Entity::getY()
{
	return y;
}
#include "entity.h"
#include <allegro.h>


Entity::Entity(int startX, int startY, int startRotation, int startHealth)
{
	
}
Entity::~Entity()
{

}

int Entity::rotate(int rotation)
{
	direction = rotation;
	return direction;
}
void Entity::movePos(int newX, int newY)
{
	x = newX;
	y = newY;
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
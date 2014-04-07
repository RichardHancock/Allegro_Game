
#include "entity.h"
#include "Ship.h"
#include <allegro.h>
#include <string>

Ship::Ship(std::string path, int startX, int startY, int startHealth
	, int maxSpeed, short startWeaponType) : Entity(startX,startY,0,startHealth), SpriteLoader(path)
{

	//Constants used for sanity purposes
	//const int Ship::FACING_UP = 0;
	//const int Ship::FACING_RIGHT = 1;
	//const int Ship::FACING_DOWN = 2;
	//const int Ship::FACING_LEFT = 3;
	//Ship::sprite = load_bitmap(path.c_str(), NULL);
	Ship::speed = maxSpeed;
	Ship::weaponType = startWeaponType;
	Entity::direction = 0;
	//Ship::turretX = 0;
	//Ship::turretY = 0;
	recalculateTurretPos();
}
Ship::~Ship()
{
	destroy_bitmap(sprite);
}
void Ship::recalculateTurretPos()
{
	switch (direction)
	{
	case FACING_UP:
		turretX = getX() + (getSprite()->w / 2);
		turretY = getY();
		break;
	case FACING_RIGHT:
		turretX = getX() + getSprite()->w;
		turretY = getY() + (getSprite()->h / 2);
		break;
	case FACING_DOWN:
		turretX = getX() + (getSprite()->w / 2);
		turretY = getY() + getSprite()->h;
		break;
	case FACING_LEFT:
		turretX = getX();
		turretY = getY() + (getSprite()->h / 2);
		break;
	}
}

void Ship::setDirection(int rotation)
{
	direction = rotation;
	recalculateTurretPos();
}
void Ship::setDirection(bool increment) //if true increment direction, if false take 1 away 
{
	if (increment)
	{
		direction++;
	} 
	else
	{
		direction--;
	}
	recalculateTurretPos();
}


void Ship::movePos(char movementDirection)
{
	// There is probably a more efficient way of trying to achieve this, but after several failed attempts
	// this is the best implementation I could get working

	if(movementDirection == 'U')
	{
		switch(direction)
		{
		case FACING_UP:
			y -= speed;
			break;
		case FACING_RIGHT:
			x += speed;
			break;
		case FACING_DOWN:
			y += speed;
			break;
		case FACING_LEFT:
			x -= speed;
			break;
		}
	}
	else if(movementDirection == 'D')
	{
		switch(direction)
		{
		case FACING_UP:
			y += speed;
			break;
		case FACING_RIGHT:
			x -= speed;
			break;
		case FACING_DOWN:
			y -= speed;
			break;
		case FACING_LEFT:
			x += speed;
			break;
		}
	}
	else if(movementDirection == 'L')
	{
		switch(direction)
		{
		case FACING_UP:
			x -= speed;
			break;
		case FACING_RIGHT:
			y -= speed;
			break;
		case FACING_DOWN:
			x += speed;
			break;
		case FACING_LEFT:
			y += speed;
			break;
		}
	}
	else if(movementDirection == 'R')
	{
		switch(direction)
		{
		case FACING_UP:
			x += speed;
			break;
		case FACING_RIGHT:
			y += speed;
			break;
		case FACING_DOWN:
			x -= speed;
			break;
		case FACING_LEFT:
			y -= speed;
			break;
		}
	}

	recalculateTurretPos();
}
int Ship::getSpeed()
{
	return speed;
}

int Ship::getTurretX()
{
	return turretX;
}
int Ship::getTurretY()
{
	return turretY;
}


/*int Entity::hit(int damage)
{
	health -= damage;

	return health;
}*/
/*
BITMAP * Ship::getSprite()
{
	return sprite;
}*/

void Ship::setSprite(std::string path)
{
	sprite = load_bitmap(path.c_str(), NULL);

	width = sprite->w;
	height = sprite->h;

}


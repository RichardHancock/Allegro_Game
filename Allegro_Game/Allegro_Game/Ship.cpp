
#include "entity.h"
#include "Ship.h"
#include <allegro.h>
#include <string>

Ship::Ship(std::string path, int startX, int startY, int direction,
	int startHealth, int maxSpeed) 
	: Entity(startX,startY,direction,startHealth), SpriteLoader(path)
{
	recalculateTurretPos(); //Initial calculation

	speed = maxSpeed;

	width = sprite->w;
	height = sprite->h;
}


void Ship::recalculateTurretPos()
{
	// Finds the middle front of the ship, so that bullet firing looks natural
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


// Mixed Getter Functions
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

	/*Moves based on direction and char input

	U = up, D = down, L = left, R = right

	There is probably a more efficient way of implementing this, but after several attempts
	this is the best implementation I could get working.*/

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


void Ship::setSprite(std::string path)
{
	sprite = load_bitmap(path.c_str(), NULL);

	width = sprite->w;
	height = sprite->h;

}


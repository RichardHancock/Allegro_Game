#include <allegro.h>
#include <string.h>
#include "EnemyShip.h"

EnemyShip::EnemyShip(std::string path, int startX, int startY, 
	int direction, int startHealth, int maxSpeed)
	: Ship(path,startX,startY,direction,startHealth,maxSpeed)
{
	//Ship::speed = maxSpeed;
	Entity::direction = 0;
	recalculateTurretPos();

	width = sprite->w;
	height = sprite->h;
}

void EnemyShip::update()
{
	switch (direction)
	{
	case FACING_UP:
		movePos('U');
		break;
	case FACING_RIGHT:
		movePos('R');
		break;
	case FACING_DOWN:
		movePos('D');
		break;
	case FACING_LEFT:
		movePos('L');
		break;
	}
	
}

void EnemyShip::teleport(int newX, int newY)
{
	x = newX;
	y = newY;
}
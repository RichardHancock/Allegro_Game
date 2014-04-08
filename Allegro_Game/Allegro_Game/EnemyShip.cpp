#include <allegro.h>
#include <string.h>
#include "EnemyShip.h"

EnemyShip::EnemyShip(std::string path, int startX, int startY, 
	int direction, int startHealth, int maxSpeed)
	: Ship(path,startX,startY,direction,startHealth,maxSpeed)
{
	//REMOVE
	//Ship::speed = maxSpeed;
	//Entity::direction = 0;
	//recalculateTurretPos();

	//width = sprite->w;
	//height = sprite->h;
}

void EnemyShip::update()
{
	movePos('U');
}

void EnemyShip::teleport(int newX, int newY)
{
	x = newX;
	y = newY;
}
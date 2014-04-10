#include <allegro.h>
#include <string.h>
#include "EnemyShip.h"

EnemyShip::EnemyShip(std::string path, int startX, int startY, 
	int direction, int startHealth, int maxSpeed)
	: Ship(path,startX,startY,direction,startHealth,maxSpeed)
{
	// Only here for visual aid, as it would run the parents (Ship) constructor anyway.
}

void EnemyShip::update()
{
	movePos('U'); //Makes the ship fly forwards no matter what direction it is facing
}


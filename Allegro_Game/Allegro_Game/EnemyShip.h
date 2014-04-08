#pragma once
#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <allegro.h>
#include <string>
#include "Ship.h"

class EnemyShip : public Ship
{
private:

public:
	EnemyShip(std::string,int,int,int,int,int);
	//~EnemyShip();

	
	void update();
};

#endif
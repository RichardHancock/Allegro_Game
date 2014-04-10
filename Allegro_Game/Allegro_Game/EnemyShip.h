#pragma once
#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <allegro.h>
#include <string>
#include "Ship.h"

class EnemyShip : public Ship
{
public:
	EnemyShip(std::string,int,int,int,int,int);
	void update(); //Make the ship move forward one (Basic AI)
};

#endif

#pragma once
#ifndef GAME_H
#define GAME_H

#include <allegro.h>
#include <vector>
#include "Ship.h"
#include "bullet.h"
#include "Entity.h"
#include "EnemyShip.h"
#include "ScreenState.h"


class Game : public ScreenState
{
public:
	struct xyPos
	{
		int x;
		int y;
	};
	xyPos xy;

	virtual int run(); //Runs all the game logic
private:
	int score;
		
	int spawnEnemy(std::vector<EnemyShip*> &,int);
	void rotate4(bool, Ship*);
	void checkKeyboard(Ship*);
	bool checkFire(Ship*, std::vector<Bullet*> &);
	bool checkRotate(Ship*);

	void checkBoundries(Ship*); 

	bool collisionTest(Entity*, Entity*);
	void getFourCorners(Entity*, std::vector<xyPos> &);
	int randomNumber(int, int);
	/*void score(int);
	int score();*/

	

};

#endif
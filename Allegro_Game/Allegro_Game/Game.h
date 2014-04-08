
#pragma once
#ifndef GAME_H
#define GAME_H

#include <allegro.h>
#include <vector>
#include "Ship.h"
#include "bullet.h"
#include "Entity.h"
#include "EnemyShip.h"



class Game
{
public:
	Game();
	//void timer_increment();
	struct xyPos
	{
		int x;
		int y;
	};
	xyPos xy;

	void run(); //Runs all the game logic, returns id of next action (Menu or Exit) 
private:
	int score;
	
	void draw(); //Draws all of the games sprites
	
	
	void spawnEnemy(std::vector<EnemyShip*> &);
	void rotate4(bool, Ship*);
	void checkKeyboard(Ship*);
	bool checkFire(Ship*, std::vector<Bullet*> &);
	bool checkRotate(Ship*);
	bool collisionTest(Entity*, Entity*);
	void getFourCorners(Entity*, std::vector<xyPos> &);
	int randomNumber(int, int);
	/*void score(int);
	int score();*/

	BITMAP *buffer;

};

#endif
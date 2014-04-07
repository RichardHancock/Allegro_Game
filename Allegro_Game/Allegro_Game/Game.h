
#pragma once
#ifndef GAME_H
#define GAME_H

#include <allegro.h>
#include <vector>
#include "Ship.h"
#include "bullet.h"

class Game
{
private:
	int score;
	void draw(); //Draws all of the games sprites

	void rotate4(bool, Ship*);
	void checkKeyboard(Ship*);
	void checkFire(Ship*, std::vector<Bullet> &);
	void checkRotate(Ship*);
	void update();
	/*void score(int);
	int score();*/

	BITMAP *buffer;
public:
	Game();
	//void timer_increment();
	

	int run(); //Runs all the game logic, returns id of next action (Menu or Exit) 
};

#endif

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
	//Structure used to easily refer to a pair of x & y coordinates
	// Almost equivalent to a Vector2 but lacks the operator overloads.
	struct xyPos
	{
		int x;
		int y;
	};

	Game();
	virtual int run(); //Runs all the game logic and drawing

private:
	int score;
	
	//Input Checks
	void checkKeyboard(Ship*); //Checks for most keyboard controls (WASD)
	bool checkRotate(Ship*); // Checks if the player wants to rotate
	bool checkFire(Ship*, std::vector<Bullet*> &); /*checks for space bar press and 
	fires a bullet*/

	//Collision Functions
	void checkBoundries(Ship*); // Makes ships "map loop" if they hit a boundary
	bool collisionTest(Entity*, Entity*); // Bounding box collision test between 2 Entities
	void getFourCorners(Entity*, std::vector<xyPos> &); // Get the 4 corners of a Entity.

	//Misc
	int randomNumber(int, int); // Random number between min and max
	void rotate4(bool, Ship*); //Limits the rotation of a Ship to 4 directions
	int spawnEnemy(std::vector<EnemyShip*> &,int); /*Spawns an enemy ship randomly
	along a screen edge*/
};

#endif
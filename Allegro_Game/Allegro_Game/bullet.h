#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "entity.h"
#include <allegro.h>

class Bullet : public Entity
{
private:
	int speed;
public:
	Bullet(int, int, int, int, int);

	void update(); // Updates the bullets position
};

#endif
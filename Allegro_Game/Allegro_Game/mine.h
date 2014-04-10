#pragma once
#ifndef MINE_H
#define MINE_H

#include <allegro.h>
#include "entity.h"
#include "spriteLoader.h"

// NOT USED IN FINAL GAME

class Mine : public Entity, public SpriteLoader
{
public:
	Mine(std::string, int, int);

	void setSprite(std::string); //Differs from parent as width and height vars need to be set.
};

#endif
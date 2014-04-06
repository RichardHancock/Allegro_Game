#pragma once
#ifndef MINE_H
#define MINE_H

#include <allegro.h>
#include "entity.h"
#include "spriteLoader.h"

class Mine : public Entity, public SpriteLoader
{
private:
	
public:
	Mine(std::string, int, int);
	~Mine();
};

#endif
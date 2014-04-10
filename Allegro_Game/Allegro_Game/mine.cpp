
#include "entity.h"
#include "spriteLoader.h"
#include "mine.h"
#include <allegro.h>
#include <string>

// NOT USED IN FINAL GAME

Mine::Mine(std::string path, int startX, int startY) 
	: Entity(startX, startY, 0, 1), SpriteLoader(path) //Multiple inheritance
{
	width = sprite->w;
	height = sprite->h;
}


void Mine::setSprite(std::string path)
{
	sprite = load_bitmap(path.c_str(), NULL);

	width = sprite->w;
	height = sprite->h;

}


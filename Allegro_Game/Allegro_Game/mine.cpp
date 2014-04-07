
#include "entity.h"
#include "spriteLoader.h"
#include "mine.h"
#include <allegro.h>
#include <string>

Mine::Mine(std::string path, int startX, int startY) 
	: Entity(startX, startY, 0, 1), SpriteLoader(path)
{
	width = sprite->w;
	height = sprite->h;
}

Mine::~Mine()
{
	destroy_bitmap(sprite);
}

void Mine::setSprite(std::string path)
{
	sprite = load_bitmap(path.c_str(), NULL);

	width = sprite->w;
	height = sprite->h;

}


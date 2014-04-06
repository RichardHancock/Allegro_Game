
#include "entity.h"
#include "spriteLoader.h"
#include "mine.h"
#include <allegro.h>
#include <string>

Mine::Mine(std::string path, int startX, int startY) 
	: Entity(startX, startY, 0, 1), SpriteLoader(path)
{

}



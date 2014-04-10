
#include "spriteLoader.h"
#include <allegro.h>
#include <string>

// SpriteLoader Implementation
// Base class to be used by objects that require a Bitmap image
// Will be often combined with other classes (Multiple Inheritance)

//Constructor
SpriteLoader::SpriteLoader(std::string path)
{
	setSprite(path);
}
//Destructor
SpriteLoader::~SpriteLoader()
{
	//When object is destroyed, delete its sprite/BITMAP.
	destroy_bitmap(sprite);
}

//Methods
BITMAP* SpriteLoader::getSprite()
{
	// Returns the object's sprite.
	return sprite;
}

void SpriteLoader::setSprite(std::string path) 
{
	// Sets the object's sprite.
	sprite = load_bitmap(path.c_str(),NULL);
}

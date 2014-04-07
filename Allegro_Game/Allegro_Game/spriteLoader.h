#pragma once
#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <allegro.h>
#include <string>

class SpriteLoader
{
	// SpriteLoader Header
	// Base class to be used by objects that require a Bitmap image
	// Will be often combined with other classes (Multiple Inheritance)

protected:
	BITMAP* sprite;

public:
	SpriteLoader(std::string);

	BITMAP* getSprite();
	virtual void setSprite(std::string);
};

#endif
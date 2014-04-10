#include "Bullet.h"
#include <allegro.h>

Bullet::Bullet(int startX, int startY, int startRotation, int startHealth, int maxSpeed) : 
Entity(startX,startY,startRotation,startHealth)
{
	// Since this class doesn't have a sprite, the spriteLoader is not inherited.


	speed = maxSpeed;

	//Because this class doesn't have a sprite I have to manually input width and height.
	height = 6;
	width = 6;

	//This being true allows the collision functions to accurately map the bounding box
	isCircleVar = true; 
}

void Bullet::update()
{
	// Moves based on inputted direction (ships direction) 

	switch (direction)
	{
	case 0:
		y -= speed;
		break;
	case 1:
		x += speed;
		break;
	case 2:
		y += speed;
		break;
	case 3:
		x -= speed;
		break;
	}
	
}

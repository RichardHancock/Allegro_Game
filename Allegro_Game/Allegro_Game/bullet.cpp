#include "Bullet.h"
#include <allegro.h>

Bullet::Bullet(int startX, int startY, int startRotation, int startHealth, int maxSpeed) : 
Entity(startX,startY,startRotation,startHealth)
{
	//x = startX;
	//y = startY;
	//direction = startRotation;
	//health = startHealth;
	speed = maxSpeed;

	//Because this object doesn't have a sprite I have to manually input width and height.
	height = 6;
	width = 6;
	isCircleVar = true;
}

void Bullet::update()
{
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
	//fire in ships direction 
}
/*void Bullet::movePos(int moveX, int moveY)
{
	x += moveX;
	y += moveY;
}

void Bullet::rotate(int rotation)
{

}

int Bullet::getX()
{
	return x;
}

int Bullet::getY()
{
	return y;
}*/
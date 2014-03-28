#include "Bullet.h"
#include <allegro.h>

Bullet::Bullet(int startX, int startY, int startRotation)
{
	x = startX;
	y = startY;
	direction = startRotation;
}

void Bullet::movePos(int moveX, int moveY)
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
}
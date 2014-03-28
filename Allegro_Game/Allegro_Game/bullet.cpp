#include "Bullet.h"
#include <allegro.h>

Bullet::Bullet(int startX, int startY)
{
	x = startX;
	y = startY;
}

void Bullet::movePos(int moveX, int moveY)
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
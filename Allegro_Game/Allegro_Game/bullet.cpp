#include "Bullet.h"
#include <allegro.h>

Bullet::Bullet(int startX, int startY, int startRotation, int startHealth) : 
Entity(startX,startY,startRotation,startHealth)
{
	x = startX;
	y = startY;
	direction = startRotation;
	health = startHealth;
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
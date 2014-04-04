#include "Bullet.h"
#include <allegro.h>

Bullet::Bullet(int startX, int startY, int startRotation, int startHealth) : 
Entity(startX,startY,startRotation,startHealth)
{
	x = startX;
	y = startY;
	direction = startRotation;
	health = startHealth;
	speed = 10;
}

void Bullet::launch()
{
	
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
#include "Ship.h"
#include <allegro.h>
#include <string>

Ship::Ship(std::string path, int startX, int startY, int startHealth, int maxSpeed, short startWeaponType)
{
	sprite = load_bitmap(path.c_str(), NULL);
	Ship::x = startX;
	Ship::y = startY;
	Ship::health = startHealth;
	Ship::speed = maxSpeed;
	Ship::weaponType = startWeaponType;
	Ship:: direction = 0;
}
int Ship::getSpeed()
{
	return speed;
}
BITMAP Ship::getSprite()
{
	return *sprite;
};

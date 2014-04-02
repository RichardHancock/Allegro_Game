
#include "entity.h"
#include "Ship.h"
#include <allegro.h>
#include <string>

Ship::Ship(std::string path, int startX, int startY, int startHealth
	, int maxSpeed, short startWeaponType) : Entity(startX,startY,0,startHealth)
{
	//allegro_message(path.c_str());
	Ship::sprite = load_bitmap(/*path.c_str()*/"playership.bmp", NULL);
	/*if (!sprite)
	{
		allegro_message("Bitmap failed");
	} else {
		allegro_message("fine");
	}*/
	//Ship::x = startX;
	//Ship::y = startY;
	//Ship::health = startHealth;
	Ship::speed = maxSpeed;
	Ship::weaponType = startWeaponType;
	Entity::direction = 0;
}
Ship::~Ship()
{
	destroy_bitmap(sprite);
}

/*void Entity::movePos(int newX, int newY)
{
	x = newX;
	y = newY;
}

int Entity::rotate(int rotation)
{
	direction = rotation;

	return direction;
}
*/
int Ship::getSpeed()
{
	return speed;
}

/*int Entity::hit(int damage)
{
	health -= damage;

	return health;
}*/

BITMAP * Ship::getSprite()
{
	return sprite;
}
void Ship::setSprite(std::string path)
{
	sprite = load_bitmap(path.c_str(), NULL);
}

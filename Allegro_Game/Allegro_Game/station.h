#include <allegro.h>
#include <string>

class Station
{
private:
	std::string name;
	BITMAP *sprite;

public:
	Station(std::string, int, int, int, std::string);
	void setName(std::string);
	std::string getName();

};
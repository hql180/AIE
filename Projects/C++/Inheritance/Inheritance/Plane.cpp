#include "Plane.h"



Plane::Plane()
{
	_toilets = 3;
	_wings = 2;
	_wheels = 6;
	_seats = 200;
	_engines = 4;
	_weight = 80000;
	_passengerLimit = _seats - 10;
}


Plane::~Plane()
{
}

Plane::Plane(int seats, int toilets, int doors)
{
	_doors = doors;
	_toilets = toilets;
	_wings = 2;
	_wheels = 6;
	_seats = seats;
	_engines = 4;
	_weight = 80000;
	_passengerLimit = _seats - 10;
}

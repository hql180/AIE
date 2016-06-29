#include "Car.h"
#include <iostream>


Car::Car()
{
	_doors = 4;
	_wheels = 4;
	_seats = 5;
	_engines = 1;
	_weight = 700;
	_passengerLimit = _seats - 1;
}

Car::~Car()
{
}

Car::Car(int doors, int seats, int weight)
{
	_doors = doors;
	_wheels = 4;
	_seats = seats;
	_engines = 1;
	_weight = weight;
	_passengerLimit = _seats - 1;
}

void Car::printSpecs()
{
	std::cout << "Doors: " << _doors << std::endl;
	std::cout << "Wheels: " << _wheels << std::endl;
	std::cout << "Seats: " << _seats << std::endl;
	std::cout << "Engines: " << _engines << std::endl;
	std::cout << "Weight: " << _weight << std::endl;
	std::cout << "Passengers: " << _passengerLimit << std::endl;
}

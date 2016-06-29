#include "TransportVehicle.h"

TransportVehicle::TransportVehicle()
{
}

TransportVehicle::~TransportVehicle()
{
}

TransportVehicle::TransportVehicle(int wheels, int seats, int engines, int weight, int passengers)
{
	_wheels = wheels;
	_seats = seats;
	_engines = engines;
	_weight = weight;
	_passengerLimit = passengers;
}


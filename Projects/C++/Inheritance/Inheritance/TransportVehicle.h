#pragma once

class TransportVehicle
{
public:
	TransportVehicle();

	~TransportVehicle();

	TransportVehicle(int wheels, int seats, int engines, int weight, int passengers);


protected:
	int _wheels;
	int _seats;
	int _engines;
	int _weight;
	int _passengerLimit;
};
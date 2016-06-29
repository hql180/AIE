#pragma once
#include "TransportVehicle.h"

class Car : public TransportVehicle
{
public:
	Car();
	~Car();
	Car(int doors, int seats, int weight);

	void printSpecs();

private:
	int _doors;
};
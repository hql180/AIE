#pragma once
#include "TransportVehicle.h"
class Plane :
	public TransportVehicle
{
public:
	Plane();
	~Plane();

	Plane(int seats, int toilets, int doors);

private:
	int _wings;
	int _toilets;
	int _doors;
};


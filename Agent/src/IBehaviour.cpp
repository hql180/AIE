#include "IBehaviour.h"




IBehaviour::~IBehaviour()
{
}

Vector3 IBehaviour::truncate(Vector3 vec, float max)
{
	if (vec.magnitude() > max)
	{
		vec = vec.normalise() * max;
		return vec;
	}
	return vec;
}

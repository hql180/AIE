#pragma once

#include "Vector3.h"

class AABB
{
public:
	AABB();
	~AABB();

	void AddPoint(Vector3 point);

	Vector3 min;
	Vector3 max;
};


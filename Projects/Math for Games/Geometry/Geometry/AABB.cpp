#include <limits> // For lowest / max values

#include "AABB.h"



AABB::AABB()
{
	float minf = std::numeric_limits<float>::lowest(); // Returns min - value :: min() returns lowest postive value
	float maxf = std::numeric_limits<float>::max();

	max = Vector3(minf, minf, minf);
	min = Vector3(maxf, maxf, maxf);
}


AABB::~AABB()
{
}

void AABB::AddPoint(Vector3 point)
{
	if (point.m_x < min.m_x)
		min.m_x = point.m_x;
	if (point.m_y < min.m_y)
		min.m_y = point.m_y;
	if (point.m_z < min.m_z)
		min.m_z = point.m_z;
	if (point.m_x > max.m_x)
		max.m_x = point.m_x;
	if (point.m_y > max.m_y)
		max.m_y = point.m_y;
	if (point.m_z > max.m_z)
		max.m_z = point.m_z;
}

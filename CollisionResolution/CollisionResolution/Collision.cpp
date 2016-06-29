#include "Collision.h"
#include "MathLib\MathLib.h"

Vector3 GetReflected(Vector3& v, Vector3& normal)
{
	// P = (-Vi.Dot(N))*N;

	Vector3 n = normal.normalise();

	Vector3 Vi = v;

	Vector3 P = n * -v.dot(normal);

	Vector3 Vf = (P * 2) + Vi;
	
	return Vf;
}
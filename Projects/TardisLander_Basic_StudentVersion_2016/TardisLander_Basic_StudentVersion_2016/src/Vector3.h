#pragma once
class Vector3
{
public:
	friend class Vector3;

	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator + (Vector3& rhs) const;

	Vector3 operator - (Vector3& rhs) const;

	Vector3 operator * (float& rhs) const;

	Vector3& operator += (Vector3& rhs);

	Vector3& operator -= (Vector3& rhs);

	Vector3& operator *= (float rhs);

	friend Vector3 operator*(float& lhs, Vector3& rhs);

	operator float*();

	float dot(Vector3 vec);

	Vector3 cross(Vector3 vec);

	float magnitude();

	Vector3 normalise();
	
	float m_x, m_y, m_z;
};


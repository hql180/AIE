#pragma once
class Vector2
{
public:
	friend class Vector2;

	Vector2();

	Vector2(float x, float y);

	~Vector2();

	Vector2 operator + (Vector2& rhs) const; 

	Vector2 operator - (Vector2& rhs) const;

	Vector2 operator * (float& rhs) const;

	Vector2& operator += (Vector2& rhs);

	Vector2& operator -= (Vector2& rhs);

	Vector2& operator *= (float rhs);

	friend Vector2 operator*(float& lhs, Vector2& rhs);

	operator float*();

	float dot(Vector2 vec);

	float magnitude();

	Vector2 normalise();


	float m_x, m_y;
};




#include "Position.h"
#include <iostream>


Position::Position()
{
	_x = 0.0f;
	_y = 0.0f;
}


Position::~Position()
{
}

Position::Position(float x, float y)
{
	_x = x;
	_y = y;
}

Position& Position::GetPosition()
{
	return* this;
}

float Position::GetX()
{
	return _x;
}

float Position::GetY()
{
	return _y;
}

void Position::SetX(float x)
{
	_x = x;
}

Position Position::operator+(Position  otherPostion)
{
	Position temp;
	temp._x = _x + otherPostion._x;
	temp._y = _y + otherPostion._y;
	return temp;
}

Position Position::operator-(Position otherPostion)
{
	Position temp;
	temp._x = _x - otherPostion._x;
	temp._y = _y - otherPostion._y;
	return temp;
}

Position & Position::operator+=(Position otherPostion)
{
	*this = *this + otherPostion;
	return *this;
}

Position & Position::operator-=(Position otherPostion)
{
	*this = *this - otherPostion;
	return *this;
}

bool Position::operator==(Position otherPostion)
{
	return _x == otherPostion._x && _y == otherPostion._y;
}

Position Position::operator*(Position otherPostion)
{
	Position temp;
	temp._x = _x * otherPostion._x;
	temp._y = _y * otherPostion._y;
	return temp;
}

Position Position::operator/(Position otherPostion)
{
	Position temp;
	temp._x = _x / otherPostion._x;
	temp._y = _y / otherPostion._y;
	return temp;
}

Position & Position::operator*=(Position otherPostion)
{
	*this = *this * otherPostion;
	return *this;
}

Position & Position::operator/=(Position otherPostion)
{
	*this = *this / otherPostion;
	return *this;
}

void Position::Print()
{
	std::cout << "{" << _x << ", " << _y << "}" << std::endl;
}

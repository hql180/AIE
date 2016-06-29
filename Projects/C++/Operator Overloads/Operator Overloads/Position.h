#pragma once
class Position
{
public:
	Position();
	~Position();

	Position(float x, float y);

	Position& GetPosition();

	float GetX();

	float GetY();

	void SetX(float x);

	Position operator + (Position otherPostion); // 2)

	Position operator - (Position otherPostion); // 2)

	Position& operator += (Position otherPostion); // 3)

	Position& operator -= (Position otherPostion); // 3)

	bool operator == (Position otherPostion); // 4)

	Position operator * (Position otherPostion);

	Position operator / (Position otherPostion);

	Position& operator *= (Position otherPostion);

	Position& operator /= (Position otherPostion);

	void Print();


	
private:
	float _x, _y;
};


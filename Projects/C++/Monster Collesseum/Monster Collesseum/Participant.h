#pragma once

class Participant
{
public:
	Participant(); 
	virtual ~Participant();

	virtual int Attack();

	int UpdateHealth(int value);

	int GetHeath();

	void GetClass();

	int GetID();
	
protected:
	int _health;
	int _armour;
	int _damage;
	int _id;
	char _participant[30];
	static int _globalID;

private:

	
};


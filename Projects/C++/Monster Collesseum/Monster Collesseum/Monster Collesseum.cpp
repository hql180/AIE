#include <iostream>
#include <time.h>
#include "Participant.h"
#include "OPHero.h"
#include "HugeRat.h"
#include "GlassCannon.h"
#include "Goblin.h"
#include <vector>

int main()
{
	srand(time(NULL));
	
	std::vector<Participant*> participants;

	participants.push_back(new OPHero());

	for (int i = 0; i < 40; ++i)
	{
		participants.push_back(new Goblin());
	}
	for (int i = 0; i < 60; ++i)
	{
		participants.push_back(new GlassCannon());
	}
	for (int i = 0; i < 120; ++i)
	{
		participants.push_back(new HugeRat());
	}
	
	int size = participants.size();

	while (size > 1)
	{
		for (int i = 0; i < size; ++i)
		{
			int index = rand() % participants.size();
			int moreRandom = rand() % 1 + 5;
			int damage = participants[i]->Attack();
			while (moreRandom > 0)
			{
				index = rand() % participants.size();
				moreRandom--;
			}
			if (i != index)
			{
				damage = participants[index]->UpdateHealth(damage);
				participants[i]->GetClass();
				std::cout << " " << participants[i]->GetID() << " attacks ";
				participants[index]->GetClass();
				std::cout << " " << participants[index]->GetID() << " for " << damage << " damage";
			}
			else
			{
				participants[i]->GetClass();
				std::cout << " " << participants[i]->GetID() << " missed their attack";
			}
			if (participants[index]->GetHeath() < 1)
			{
				std::cout << std::endl;
				participants[index]->GetClass();
				std::cout << " " << participants[index]->GetID() << " dies!";
				participants.erase(participants.begin() + index);
				size = participants.size();


				
			}
			std::cout << std::endl;
		}
	}

	

	participants[0]->GetClass(); 
	std::cout << " " << participants[0]->GetID() << " wins! " << participants[0]->GetHeath() << " health remaining" << std::endl;
		

	system("pause");
    return 0;
}


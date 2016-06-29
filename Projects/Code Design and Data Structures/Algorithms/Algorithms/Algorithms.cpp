#include <iostream>

void printList(int* list, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}

void sort(int* list, int length)
{
	if (length < 0)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		while (true)
		{
			bool stillRunning = false;

			for (int i = 0; i < length; ++i)
			{
				if (i + 1 < length)
				{
					if (list[i] > list[i + 1])
					{
						int temp = list[i];
						list[i] = list[i + 1];
						list[i + 1] = temp;
						stillRunning = true;
					}
				}
			}
			if (stillRunning == false)
			{
				printList(list, length);
				break;
			}
			printList(list, length);
		}
	}
}

void q1()
{
	// sorts a list from lowest to highest or vice versa

	/*if list empty do

		return 0

	else

		sort(list)
	{
		while true
			stillrunning = false

			placeinlist <-0

			while placeinlist < listlength

				if list placeinlist < next in list
					swap values around
					stillruning <-true
					end if
					increment placeinlist

					if stillrunning false

						return list

						end if

						end while
	}*/
}

void q1c()
{
	int list[17] = { 12, 23, 1, 2, 3, 45, 10, 100, 20, 12, 123, 1, 2, 3, 342, 325, 4565 };

	sort(list, 17);


}

//take player 1 input
//check if selected grid has marker in it if not
//mark input on grid
//check for winner
//repeat first 4 steps for player2
//alternate turns until winner is found or no more grid spaces available
//
//winner = none
//input
//currentplayer
//3x3 grid
//
//while winner = none
//input <-currentplayer input
//
//	if input target empty
//		place currentplayer marker
//		end if
//		else
//		ask currentplayer to select another grid
//		input <-currentplayer
//		end else
//
//		check for winner if found
//		winner <-currentplayer
//		else
//		currentplayer <-player2 / player1
//		end else
//
//		end while
//
int main()
{
	q1c();
	
	system("pause");
    return 0;
}


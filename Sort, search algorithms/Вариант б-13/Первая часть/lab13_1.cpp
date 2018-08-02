#include <iostream>

#include "set.hpp"

int main()
{
	const int PLAYER_SIZE = 5;
	
	IntegerSet * pl[PLAYER_SIZE];

	for (int i = 0; i < PLAYER_SIZE; i++) pl[i] = IntegerSetCreate();

	char cmd;
	int player1, player2, card1, card2;

	while (true)
	{
		std::cin >> cmd;
		switch (cmd)
		{
		case 'A':
			std::cin >> player1 >> card1;
			if ((player1 > 0 && player1 < PLAYER_SIZE) && (card1 > 0 && card1 < 51))
			{
				IntegerSetInsertKey(*pl[player1 - 1], card1);
				if (IsWin(*pl[player1 - 1]))
				{
					std::cout << "PLAYER #" << player1 << " WIN." << std::endl;
					return 0;
				}
			}
			else
				std::cout << "Wrong input." << std::endl;
			break;
		case 'E':
			std::cin >> player1 >> card1 >> player2 >> card2;

			if ((player1 > 0 && player1 < PLAYER_SIZE) && (card1 > 1 && card1 < 51) &&
				(player2 > 0 && player2 < PLAYER_SIZE) && (card2 > 1 && card2 < 51))
			{
				if (!IntegerSetHasKey(*pl[player1 - 1], card1) || !IntegerSetHasKey(*pl[player2 - 1], card2))
				{
					std::cout << "One player hasn't got such card." << std::endl;
					break;
				}
				IntegerSetInsertKey(*pl[player1-1], card2);
				IntegerSetInsertKey(*pl[player2-1], card1);
				IntegerSetDeleteKey(*pl[player1-1], card1);
				IntegerSetDeleteKey(*pl[player2-1], card2);
			}
			else
				std::cout << "Wrong input" << std::endl;
			break;
		case 'R':
			std::cin >> player1 >> card1;
			if ((player1 > 0 && player1 < PLAYER_SIZE) && (card1 > 1 && card1 < 51))
				if (!IntegerSetIsEmpty(*pl[player1-1]))
					IntegerSetDeleteKey(*pl[player1-1], card1);
				else
					std::cout << "Player hasn't got this card." << std::endl;
			else
				std::cout << "Wrong input" << std::endl;
			break;
		case 'S':
			std::cin >> player1;
			if (player1 > 0 && player1 < PLAYER_SIZE)
				std::cout << IntegerSetSize(*pl[player1-1]) << std::endl;
			else
				std::cout << "Wrong input" << std::endl;
			break;
		default:
			std::cout << "Wrong cmd." << std::endl;
			break;
		}
	}

	for (int i = 0; i < PLAYER_SIZE; i++) IntegerSetDestroy(pl[i]);
	return 0;
}


#include <iostream>
#include <ctime>
#include <cstdlib>

#include "integer_map.hpp"

bool checkHouseNumber(int _number);

int main()
{
	srand((unsigned)time(nullptr));

	IntegerMap * keys = IntegerMapCreate();
	IntegerMap * habitans = IntegerMapCreate();

	for (int i = 0; i < 100; i++)
	{
		IntegerMapInsertKey(*keys, i + 1, rand() % 5 + 1);
		IntegerMapInsertKey(*habitans, i + 1, 0);
	}

	char command;
	int houseNumber;
	
	while (std::cin)
	{
		std::cin >> command;
		if (std::cin)
			switch (command)
			{
			case 'E':
				std::cin >> houseNumber;
				if (!checkHouseNumber(houseNumber))
				{
					std::cout << "Number must be a value between 1 and 100";
					break;
				}
				if (IntegerMapGet(*habitans, houseNumber) == IntegerMapGet(*keys,houseNumber))
					std::cout << "The room is already occupied." << std::endl;
				else
						IntegerMapInsertKey(*habitans, houseNumber, IntegerMapGet(*habitans,houseNumber)+1);
				break;
			case 'L':
				std::cin >> houseNumber;
				if (!checkHouseNumber(houseNumber))
				{
					std::cout << "Number must be a value between 1 and 100";
					break;
				}
				if (IntegerMapGet(*habitans, houseNumber) == 0)
					std::cout << "The room is already left." << std::endl;
				else
					IntegerMapInsertKey(*habitans, houseNumber, IntegerMapGet(*habitans, houseNumber)-1);
				break;
			case 'S':
				std::cin >> houseNumber;
				if (!checkHouseNumber(houseNumber))
				{
					std::cout << "Number must be a value between 1 and 100";
					break;
				}
				std::cout << "ALL : " << IntegerMapGet(*keys, houseNumber) << " NOW : " << IntegerMapGet(*habitans, houseNumber) << std::endl;
				break;
			default:
				std::cout << "Wrong command." << std::endl;
				break;
			}
		else
			break;
	}

	IntegerMapDestroy(habitans);
	IntegerMapDestroy(keys);
	return 0;
}

bool checkHouseNumber(int _number)
{
	return _number > 0 && _number < 101;
}
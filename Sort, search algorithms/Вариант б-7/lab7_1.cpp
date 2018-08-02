#include <iostream>

#include "map.hpp"

int main()
{
	Map * pMap = MapCreate();

	MapInsertKey(*pMap, 1, "Gillete");
	MapInsertKey(*pMap, 2, "Croissant");
	MapInsertKey(*pMap, 3, "Trouffle");
	MapInsertKey(*pMap, 4, "Potato");
	MapInsertKey(*pMap, 50, "Fluffy bunny");
	MapInsertKey(*pMap, 99, "Mango");
	MapInsertKey(*pMap, 43, "Chocolate");
	MapInsertKey(*pMap, 29, "Cheesecake");

	int command = 0;
	while (true)
	{
		std::cin >> command;
		if (command == 0)
		{
			MapDestroy(pMap);
			return 0;
		}
		if (command < 1 || command > 100)
		{
			std::cout << "Unavailable ID. Values can be only from 1 to 100." << std::endl;
			continue;
		}
		if (MapHasKey(*pMap, command))
			std::cout << MapGet(*pMap, command) << std::endl;
		else
			std::cout << "GOOD DOESN'T EXIST" << std::endl;
	};

	return 0;
}
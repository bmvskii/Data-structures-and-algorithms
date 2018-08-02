#include <iostream>

#include "map.hpp"

enum Codes {Ukraine = 482, Poland = 590, Turkey = 869, Albania = 355, Algeria = 21,France = 33, Iceland = 354};

int main()
{
	Map * pMap = MapCreate();


	MapInsertKey(*pMap, 482, "Ukraine"); 
	MapInsertKey(*pMap, 590, "Poland");
	MapInsertKey(*pMap, 869, "Turkey");
	MapInsertKey(*pMap, 355, "Ukraine");
	MapInsertKey(*pMap, 21, "Algeria");
	MapInsertKey(*pMap, 33, "France");
	MapInsertKey(*pMap, 354, "Iceland");

	int code;
	while (true)
	{
		std::cin >> code;
		if (code)
			if (MapGet(*pMap, code))
				std::cout << MapGet(*pMap, code) << std::endl;
			else
				std::cout << "Error: unrecognized country code" << std::endl;
		else
			break;
	}

	MapDestroy(pMap);
	return 0;
}
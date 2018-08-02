#include <iostream>
#include <clocale>

#include "map.hpp"

int main()
{
	setlocale(LC_ALL, "rus");
	
	//создаем отображение
	Map * pMap = MapCreate();

	MapInsertKey(*pMap, "Dnipropetrovska", 2000000);
	MapInsertKey(*pMap, "Uzhgorodska", 3500000);
	MapInsertKey(*pMap, "Hersonska", 1500000);
	MapInsertKey(*pMap, "Dontetska", 9500000);
	MapInsertKey(*pMap, "Ternopilska", 700000);

	char buffer[80];
	std::cin.getline(buffer, sizeof(buffer));

	//проверка на существование области в отображении
	MapHasKey(*pMap, buffer) ? std::cout << MapGet(*pMap, buffer) << std::endl : std::cout << "О данной области ничего не найдено." << std::endl;

	//уничтожение
	MapDestroy(pMap);
	return 0;
}
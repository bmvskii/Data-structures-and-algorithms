#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include "map.hpp"
#include "date_vector.hpp"
#include "test.hpp"

int main(int argc, char ** argv)
{
	hasCommandLineArgument(argc, std::cout);
	fileOpening(argv[1], std::cout);

	double value = 0;
	Date key;
	char buffer[512];
	std::ifstream file(argv[1]);
	Map * pM = MapCreate();

	functionalTest(*pM, file, std::cout);

	std::cout << "Searching date (Format : dd/mm/yyyy ) : ";
	std::cin.getline(buffer, sizeof(buffer));
	sscanf(buffer, "%2d/%2d/%4d", &key.m_day, &key.m_month, &key.m_year);
	
	if (MapFind(*pM, key) == -1)
		value = MapGetAverage(*pM, key);
	else
		value = MapFind(*pM, key);

	if (value != -1)
		std::cout << value << std::endl;
	else
		std::cout << "Anything is found" << std::endl;

	MapDestroy(pM);
	return 0;
}
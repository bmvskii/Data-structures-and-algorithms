#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include "integer_map.hpp"
#include "test.hpp"

int parseDate(const char *);

int main(int argc, char ** argv)
{
	testOpeningAFile(argv[1]);

	int    date;
	double curse = 0;

	char  buffer[80];
	char  * tempBuffer;

	std::ifstream file(argv[1]);
	IntegerMap * pMap = IntegerMapCreate();

	while (!file.eof())
	{
		file.getline(buffer, sizeof(buffer));
		tempBuffer = strtok(buffer, " ");
		date = parseDate(tempBuffer);
		
		tempBuffer += strlen(tempBuffer) + 1;
		testConveringCurse(tempBuffer);

		curse = atof(tempBuffer);
		testIsPositiveCurse(curse);

		IntegerMapInsertKey(*pMap, date, curse);
	}
	
	char searchDate[11];
	int  integerSearchDate;
	double  searchCurse = 0;

	std::cout << "TYPE DATE (dd/mm/yyyy) : ";
	std::cin.getline(searchDate, sizeof(searchDate));

	integerSearchDate = parseDate(searchDate);
	
	if (IntegerMapBinaryFind(*pMap, integerSearchDate) != -1)
		searchCurse = IntegerMapBinaryFind(*pMap, integerSearchDate);
	else 
		searchCurse = IntegerMapFindAverageValue(*pMap, integerSearchDate);
		
	if (searchCurse)
		std::cout << searchCurse << std::endl;
	else
		std::cout << "NOTHING ABOUT THIS DATE\n";

	IntegerMapDestroy(pMap);
	return 0;
}

int parseDate(const char * _src)
{
	int day, month, year;
	char * buffer = new char[strlen(_src) + 1];
	strcpy(buffer, _src);

	char * current = strtok(buffer, "/");
	testConvertingDay(current);
	day = atoi(current);

	current = strtok(NULL, "/");
	testConvertingMonth(current);
	month = atoi(current);

	current = strtok(NULL, " ");
	testConvertingYear(current);
	year = atoi(current);

	testWrongDay(day);
	testWrongMonth(month);
	testWrongYear(year);

	return year * 10000 + month * 100 + day;
}
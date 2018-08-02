#include "test.hpp"

#include <cassert>
#include <fstream>
#include <iostream>

void testOpeningAFile(const char * _path)
{
	std::ifstream f(_path);
	if (!f.is_open())
	{
		std::cout << "Can't open a file." << std::endl;
		exit(1);
	}
}

void testConvertingDay(char * _day)
{
	assert(atoi(_day));
}

void testConvertingMonth(char * _month)
{
	assert(atoi(_month));
}

void testConvertingYear(char * _year)
{
	assert(atoi(_year));
}

void testWrongDay(int _day)
{
	assert(_day > 0 && _day < 32);
}

void testWrongMonth(int _month)
{
	assert(_month > 0 && _month < 13);
}

void testWrongYear(int _year)
{
	assert(_year > 0 && _year < 2018);
}

void testConveringCurse(char * _curse)
{
	assert(atof(_curse));
}

void testIsPositiveCurse(double _curse)
{
	assert(_curse > 0);
}
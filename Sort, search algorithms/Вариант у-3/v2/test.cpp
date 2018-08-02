#define _CRT_SECURE_NO_WARNINGS

#include "test.hpp"
#include "date_vector.hpp"
#include "map.hpp"

#include <cassert>
#include <fstream>

void hasCommandLineArgument(int _argc, std::ostream & _s)
{
	assert(_argc == 2);
	_s << "TEST #1 : COMMAND LINE ARGUMENTS - PASSED" << std::endl;
}

void fileOpening(const char * _path, std::ostream & _s)
{
	std::ifstream f(_path);
	assert(f.is_open());
	_s << "TEST #2 : FILE OPENING - PASSED" << std::endl;
}

void trueDataInDate(char * _str)
{
	Date d;
	assert(sscanf(_str, "%2d/%2d/%4d", &d.m_day, &d.m_month, &d.m_year));
}

void convertingCurse(char * _str)
{
	assert(atof(_str));
}

void isPositiveCurse(double _curse)
{
	assert(_curse > 0);
}

void isDateRangeTrue(int _day, int _month, int _year)
{
	assert(_day > 0 && _day < 32);
	assert(_month > 0 && _month < 13);
	assert(_year > 0 && _year < 2018);
}

void functionalTest(Map & _map, std::ifstream & _is, std::ostream & _stream)
{
	char buffer[512];
	while (!_is.eof())
	{
		_is.getline(buffer, sizeof(buffer));
		MapParseData(_map, buffer);
	}

	_stream << "TEST #3 : FUNCTIONAL - PASSED\n* TRUE DATA(CONV + RANGES);\n* TRUE CURSE(CONV + POSIT);\n" << std::endl;
}
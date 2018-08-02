#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

struct Map;

void hasCommandLineArgument(int _argc, std::ostream & _s);

void fileOpening(const char * _path, std::ostream & _s);

void trueDataInDate(char * _str);

void convertingCurse(char * _str);

void isPositiveCurse(double _curse);

void isDateRangeTrue(int _day, int _month, int _year);

void functionalTest(Map & _map, std::ifstream & _is, std::ostream & _stream);

#endif // !TEST_HPP

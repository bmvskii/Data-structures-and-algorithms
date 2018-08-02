#include "test.hpp"
#include <fstream>

void TestArguments(int _argc)
{
	assert(_argc >= 1);
}

void TestFilePath(int _argc)
{
	assert(_argc >= 2);
}

void TestAge( int _argc)
{
	assert(_argc == 3);
}

void TestAgeConvert( char * _age)
{
	assert(atoi(_age));
}

void TestTrueData(char * _age)
{
	assert(atoi(_age));
}

void TestAgeIsntNegative( char * _age)
{
	assert(atoi(_age) > 0);
}

void TestTruePath( char * _path)
{
	std::ifstream file(_path);
	assert(file.is_open());
}
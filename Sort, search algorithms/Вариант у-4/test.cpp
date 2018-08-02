#include "test.hpp"
#include "string_set.hpp"

#include <fstream>
#include <iostream>
#include <cassert>


void cmdTest(int _argc)
{
	if (_argc == 1)
	{
		std::cout << "Any arguments in the command line." << std::endl;
		exit(1);
	}
}

void openFileTest(const char * _path)
{
	std::fstream file(_path);
	if (!file.is_open())
	{
		std::cout << "Cannot open a file." << std::endl;
		exit(1);
	}
}

void setWorkingTest()
{
	StringSet * pSet = StringSetCreate();

	StringSetInsertKey(*pSet, "AAAAA");
	StringSetInsertKey(*pSet, "BBBBB");
	StringSetInsertKey(*pSet, "CCCCC");

	assert(StringSetHasKey(*pSet, "AAAAA"));
	assert(StringSetHasKey(*pSet, "BBBBB"));
	assert(!StringSetHasKey(*pSet, "WWWWW"));

	StringSetDeleteKey(*pSet, "CCCCC");
	assert(!StringSetHasKey(*pSet, "CCCCC"));

	StringSetDestroy(pSet);
}
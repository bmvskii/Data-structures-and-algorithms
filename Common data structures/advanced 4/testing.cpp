#define _CRT_SECURE_NO_WARNINGS

#include "testing.hpp"

void testCommandLineArguments(int _argc, const char * _text)
{
	assert(_argc >= 1);
	std::cout << _text << std::endl;
}

void testCommandLineArgumentsFirstFile(int _argc, const char * _text)
{
	assert(_argc >= 2);
	std::cout << _text << std::endl;
}

void testCommandLineArgumentsSecondFile(int _argc, const char * _text)
{
	assert(_argc >= 3);
	std::cout << _text << std::endl;
}

void testCommandLineArgumentsThirdFile(int _argc, const char * _text)
{
	assert(_argc == 4);
	std::cout << _text << std::endl;
}

void testCreateFile(const char * _path, const char * _text)
{
	std::fstream file(_path);
	assert(file.is_open());
	std::cout << _text << std::endl;
}

void testWrongFileData(Vector & _v, std::ifstream & _s,const char * _text)
{
	char buffer[256];
	int ID;
	double summary;
	Account acc;

	while (!_s.eof())
	{
		_s.getline(buffer, sizeof(buffer));

		char * pCurrent = strtok(buffer, " ");
		assert(atoi(pCurrent));
		ID = atoi(pCurrent);

		pCurrent = strtok(NULL, " ");
		assert(atof(pCurrent));
		summary = atof(pCurrent);
		
		acc.m_ID = ID;
		acc.m_summary = summary;

		VectorPushBack(_v, acc);
	}

	std::cout << _text << std::endl;
}
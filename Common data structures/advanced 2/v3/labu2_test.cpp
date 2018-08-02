#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>

#include "list.hpp"
#include "test.hpp"

int main(int argc, char ** argv)
{
	//запускаем основные тесты
	TestArguments(argc);
	TestFilePath(argc);
	TestAge(argc);
	TestTruePath(argv[1]);
	TestAgeConvert(argv[2]);
	TestAgeIsntNegative(argv[2]);

	char b[256];
	List * l = new List();
	ListInit(*l);
	
	std::ifstream f(argv[1]);
	while (!f.eof())
	{
		Human h;
		f.getline(b, sizeof(b));

		char * p = strtok(b, " ");
		h.m_sename = new char[strlen(p) + 1];
		strcpy(h.m_sename, p);

		p = strtok(NULL, " ");

		//тестируем возраст из файла
		TestTrueData(p);
		
		h.m_age = atoi(p);
		ListPushBack(*l, h);
	}

	ListPrint(*l, std::cout, atoi(argv[2]));

	ListDestroy(*l);
	return 0;
}
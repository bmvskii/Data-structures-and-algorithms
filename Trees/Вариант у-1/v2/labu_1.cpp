#define _CRT_SECURE_NO_WARNINGS
#include "bstree.hpp"
#include "testing.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

//функция печати значения в узле
void printNode(const BSTree::Node & _pNode, std::ostream & _stream)
{
	_stream << _pNode.m_key << std::endl;
}

void showWorkingTime(const char * _inpath, const char * _outpath, double _divider)
{
	char buffer[2048];
	BSTree * pBST = BSTreeCreate();
	std::ifstream in(_inpath);
	std::ofstream out(_outpath);

	clock_t start = clock();
	while (!in.eof())
	{
		in.getline(buffer, sizeof(buffer));
		BSTreeInsertKey(*pBST, buffer);
	}
	BSTreeSymmetricWalk(*pBST, printNode, out);
	clock_t end = clock();

	std::cout << (double)(end - start) / _divider << std::endl;
	BSTreeDestroy(pBST);
}

int main(int argc, char ** argv)
{
	//запуск основных тестов
	commandLineArgumentsTest(argc);
	fileOpenTest(argv[1]);
	BSTreeFunctionalTest();

	//запуск основной функции
	showWorkingTime(argv[1], argv[2], 100000);

	return 0;
}

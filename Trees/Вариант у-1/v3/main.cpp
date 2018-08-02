#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <clocale>

#include "bstree.hpp"
#include "tests.hpp"

//функция печати значения в узле
void print(const BSTree::Node & _pNode, std::ostream & _stream);

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "rus");
	//тестируем командную строку,путь для входного файла и функционал дерева
	cmdTest(argc); 
	fileTest(argv[1]);
	BSTreeTest();

	//буфер для считывания строки из файла
	char text[1024];
	//точность показателя времени
	double precision = 10000;
	std::ifstream sourceFile(argv[1]);
	std::ofstream destinationFile(argv[2]);

	BSTree * pTree = BSTreeCreate();
	//время запуска
	clock_t timeOn = clock();
	while (!sourceFile.eof()){
		sourceFile.getline(text, sizeof(text));
		BSTreeInsertKey(*pTree, text);
	}

	//симметрический обход дерева
	BSTreeSymmetricWalk(*pTree, print, destinationFile);
	//время окончания
	clock_t timeOff = clock();

	std::cout << "Время работы дерева : " << (double)(timeOff - timeOn) / precision << std::endl;
	
	//уничтожение дерева
	BSTreeDestroy(pTree);
	return 0;
}

void print(const BSTree::Node & _pNode, std::ostream & _stream)
{
	_stream << _pNode.m_key << std::endl;
}

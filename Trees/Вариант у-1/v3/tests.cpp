#define _CRT_SECURE_NO_WARNINGS

#include "bstree.hpp"

#include <cstring>
#include <fstream>
#include <cassert>

//функция тестирования аргументов командной строки
void cmdTest(int _argc)
{
	if (_argc == 1){
		std::cout << "Nothing is passed into a cmd." << std::endl;
		exit(1);
	}
}

//функция тестирования открытия файла
void fileTest(const char * _path)
{
	std::fstream f(_path);
	if (!f.is_open()){
		std::cout << "Cannot open a file path : " << _path << std::endl;
		exit(1);
	}

}

void BSTreeTest()
{
	BSTree * pBST = BSTreeCreate();
	
	BSTreeInsertKey(*pBST, "KEY1");
	BSTreeInsertKey(*pBST, "KEY2");
	BSTreeInsertKey(*pBST, "KEY3");
	BSTreeInsertKey(*pBST, "KEY4");

	assert(BSTreeHasKey(*pBST, "KEY1"));
	assert(BSTreeHasKey(*pBST, "KEY4"));

	assert(!strcmp(BSTreeMaximum(*pBST), "KEY4"));
	assert(!strcmp(BSTreeMinimum(*pBST), "KEY1"));

	BSTreeDeleteKey(*pBST, "KEY2");
	BSTreeDeleteKey(*pBST, "KEY3");

	assert(!BSTreeHasKey(*pBST, "KEY2"));
	assert(!BSTreeHasKey(*pBST, "KEY3"));

	BSTreeDestroy(pBST);
}
#define _CRT_SECURE_NO_WARNINGS

#include "bstree.hpp"

#include <cstring>
#include <fstream>
#include <cassert>

void commandLineArgumentsTest(int _argc)
{
	if (_argc == 1)
	{
		std::cout << "Any arguments in command line." << std::endl;
		exit(1);
	}
}

void fileOpenTest(const char * _path)
{
	std::fstream f(_path);
	if (!f.is_open()) exit(1);
}

void BSTreeFunctionalTest()
{
	//������� ������
	BSTree * pBST = BSTreeCreate();

	//��������� �����
	BSTreeInsertKey(*pBST, "AAAA");
	BSTreeInsertKey(*pBST, "BBBB");
	BSTreeInsertKey(*pBST, "CCCC");
	BSTreeInsertKey(*pBST, "DDDD");
	BSTreeInsertKey(*pBST, "EEEE");

	//��������� ������� ������
	assert(BSTreeHasKey(*pBST, "AAAA"));
	assert(BSTreeHasKey(*pBST, "BBBB"));
	assert(BSTreeHasKey(*pBST, "CCCC"));
	assert(BSTreeHasKey(*pBST, "DDDD"));
	assert(BSTreeHasKey(*pBST, "EEEE"));

	//��������� ������������ � ����������� �������
	assert(!strcmp(BSTreeMaximum(*pBST), "EEEE"));
	assert(!strcmp(BSTreeMinimum(*pBST), "AAAA"));

	//������ 1 ����
	BSTreeDeleteKey(*pBST, "AAAA");

	//��������� , ��� ��� ���
	assert(!BSTreeHasKey(*pBST, "AAAA"));
	
	//������� ������
	BSTreeDestroy(pBST);
}
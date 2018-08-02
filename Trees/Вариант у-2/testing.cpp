#define _CRT_SECURE_NO_WARNINGS
#include "testing.hpp"
#include "bstree.hpp"

#include <fstream>
#include <cassert>
#include <iostream>

void fileOpeningTest(const char * _path)
{
	std::fstream file(_path);
	if (!file.is_open())
	{
		std::cout << "Неверный путь файла : " << _path << std::endl;
		exit(1);
	}
}

void treeFunctionalTest()
{

	BSTree * tree = BSTreeCreate();
	Student s1, s2, s3;

	s1.m_lastName = new char[strlen("AAAAAA") + 1];
	strcpy(s1.m_lastName, "AAAAAA");
	s1.m_mark = 90;
	
	s2.m_lastName = new char[strlen("BBBBBB") + 1];
	strcpy(s2.m_lastName, "BBBBBB");
	s2.m_mark = 80;

	s3.m_lastName = new char[strlen("CCCCCC") + 1];
	strcpy(s3.m_lastName, "CCCCCC");
	s3.m_mark = 70;

	BSTreeInsertKey(*tree, s1);
	BSTreeInsertKey(*tree, s2);
	BSTreeInsertKey(*tree, s3);

	assert(BSTreeHasKey(*tree, s1));
	assert(BSTreeHasKey(*tree, s3));

	assert(!strcmp(BSTreeMinimum(*tree).m_lastName, "AAAAAA"));
	assert(!strcmp(BSTreeMaximum(*tree).m_lastName, "CCCCCC"));

	BSTreeDeleteKey(*tree, s1);
	BSTreeDeleteKey(*tree, s2);

	assert(!BSTreeHasKey(*tree, s1));
	assert(!BSTreeHasKey(*tree, s2));
	assert(BSTreeHasKey(*tree,	s3));

	BSTreeDestroy(tree);
}
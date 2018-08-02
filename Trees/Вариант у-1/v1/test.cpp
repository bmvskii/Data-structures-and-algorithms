#define _CRT_SECURE_NO_WARNINGS

#include "bstree.hpp"

#include <cstring>
#include <fstream>
#include <cassert>

void testFileOpening(const char * _path)
{
	std::fstream file(_path);
	if (!file.is_open())
		exit(1);
}

void testFunctional()
{
	BSTree * tree = BSTreeCreate();

	BSTreeInsertKey(*tree, "First key");
	BSTreeInsertKey(*tree, "Second key");
	BSTreeInsertKey(*tree, "Third key");

	assert(BSTreeHasKey(*tree, "First key"));
	assert(BSTreeHasKey(*tree, "Third key"));

	assert(!strcmp(BSTreeMaximum(*tree), "Third key"));
	assert(!strcmp(BSTreeMinimum(*tree), "First key"));

	BSTreeDeleteKey(*tree, "First key");
	BSTreeDeleteKey(*tree, "Second key");

	assert(!BSTreeHasKey(*tree, "First key"));
	assert(!BSTreeHasKey(*tree, "Second key"));
	assert(BSTreeHasKey(*tree, "Third key"));

	BSTreeDestroy(tree);
}
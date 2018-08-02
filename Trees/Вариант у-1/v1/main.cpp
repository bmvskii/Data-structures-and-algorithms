#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

#include "bstree.hpp"
#include "test.hpp"

void printNode(const BSTree::Node & _pNode, std::ostream & _stream);

int main(int argc, char ** argv)
{
	if (argc == 1)
	{
		std::cout << "Any arguments in command line." << std::endl;
		return -1;
	}

	testFileOpening(argv[1]);
	testFunctional();

	BSTree * tree = BSTreeCreate();

	std::ifstream file(argv[1]);
	std::ofstream output(argv[2]);

	char buffer[4096];

	clock_t benchStart = clock();

	while (!file.eof())
	{
		file.getline(buffer, sizeof(buffer));
		BSTreeInsertKey(*tree, buffer);
	}

	BSTreeSymmetricWalk(*tree, printNode, output);

	clock_t benchEnd = clock();

	std::cout << "TIME : " << (double)(benchEnd - benchStart) / (double)10000 << std::endl;

	BSTreeDestroy(tree);
	return 0;
}

void printNode(const BSTree::Node & _pNode, std::ostream & _stream)
{
	_stream << _pNode.m_key << std::endl;
}
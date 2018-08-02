#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

#include "bstree.hpp"
#include "test.hpp"

void runWithoutTests(int argc, char ** argv);
void printNode(const BSTree::Node & _node, std::ostream & _stream);

int main(int argc, char ** argv)
{
	if (argc == 1)
	{
		std::cout << "Any arguments in the command line." << std::endl;
		return 0;
	}

	if (argc == 2 && !_stricmp(argv[1], "test"))
		testTreeFunctional();
	else
		runWithoutTests(argc, argv);

	return 0;
}

void runWithoutTests(int argc, char ** argv)
{
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2]);
	
	BSTree * pBST;
	
	if (argc == 4)
	{
		if (!_stricmp(argv[3], "-i"))
			pBST = BSTreeCreate(_stricmp);
	}
	else
		pBST = BSTreeCreate();

	char buffer[512];
	
	while (!in.eof())
	{
		in.getline(buffer, sizeof(buffer));
		BSTreeInsertKey(*pBST, buffer);
	}

	BSTreeSymmetricWalk(*pBST, printNode, out);

	BSTreeDestroy(pBST);
}

void printNode(const BSTree::Node & _node, std::ostream & _stream)
{
	_stream << _node.m_key << std::endl;
}
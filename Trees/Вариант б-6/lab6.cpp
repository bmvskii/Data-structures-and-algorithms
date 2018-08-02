#define _CRT_SECURE_NO_WARNINGS

#include "tree_static.hpp"

#include <iostream>
#include <cassert>
#include <cstring>

void PrintNodeLabel(const Tree & _t, int _nodeIndex);

int main()
{ 
	const int TREE_SIZE = 7;
	Tree * pTree = TreeCreate(TREE_SIZE);

	TreeSetLabel(*pTree, 0, "Assembler");
	TreeSetLabel(*pTree, 1, "C");
	TreeSetLabel(*pTree, 2, "C++");
	TreeSetLabel(*pTree, 3, "C#");
	TreeSetLabel(*pTree, 4, "Perl");
	TreeSetLabel(*pTree, 5, "Php");
	TreeSetLabel(*pTree, 6, "Lisp");

	TreeSetParentIndex(*pTree, 1, 0);
	TreeSetParentIndex(*pTree, 4, 0);
	TreeSetParentIndex(*pTree, 6, 0);
	TreeSetParentIndex(*pTree, 2, 1);
	TreeSetParentIndex(*pTree, 3, 1);
	TreeSetParentIndex(*pTree, 5, 4);

	assert(!strcmp(TreeGetLabel(*pTree,TreeGetRootIndex(*pTree)),"Assembler"));

	assert(!strcmp(TreeGetLabel(*pTree, TreeGetParentIndex(*pTree, 5)),"Perl"));

	assert(!strcmp(TreeGetLabel(*pTree, TreeGetLeftmostChildIndex(*pTree, 0)), "C"));

	assert(!strcmp(TreeGetLabel(*pTree, TreeGetRightSiblingIndex(*pTree,2)), "C#"));
	
	TreeDirectWalk(*pTree, &PrintNodeLabel); std::cout << std::endl;

	TreeReverseWalk(*pTree, &PrintNodeLabel); std::cout << std::endl;

	TreeSymmetricWalk(*pTree, &PrintNodeLabel); std::cout << std::endl;

	TreeDestroy(pTree);
	return 0;
}

void PrintNodeLabel(const Tree & _t, int _nodeIndex)
{
	std::cout << TreeGetLabel(_t, _nodeIndex) << ' ';
}
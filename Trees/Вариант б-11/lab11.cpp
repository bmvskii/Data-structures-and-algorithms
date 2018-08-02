#include "tree_static.hpp"

#include <iostream>
#include <cassert>

void PrintNodeLabel(const Tree & _t, int _nodeIndex)
{
	std::cout << TreeGetLabel(_t, _nodeIndex) << ' ';
}

int main()
{
	Tree * pTree = TreeCreate(7);
	int treeIndex;

	TreeSetLabel(*pTree, 0, "KEY1");
	TreeSetLabel(*pTree, 1, "KEY2");
	TreeSetLabel(*pTree, 2, "KEY3");
	TreeSetLabel(*pTree, 3, "KEY4");
	TreeSetLabel(*pTree, 4, "KEY5");
	TreeSetLabel(*pTree, 5, "KEY6");

	TreeSetParentIndex(*pTree, 1, 0);
	TreeSetParentIndex(*pTree, 2, 0);
	TreeSetParentIndex(*pTree, 3, 1);
	TreeSetParentIndex(*pTree, 4, 1);
	TreeSetParentIndex(*pTree, 5, 2);
	
	
	assert(!strcmp(TreeGetLabel(*pTree, TreeGetRootIndex(*pTree)),"KEY1"));
	assert(!strcmp(TreeGetLabel(*pTree, TreeGetLeftmostChildIndex(*pTree,0)), "KEY2"));
	assert(!strcmp(TreeGetLabel(*pTree, TreeGetParentIndex(*pTree,5)), "KEY3"));
	assert(!strcmp(TreeGetLabel(*pTree, TreeGetRightSiblingIndex(*pTree,3)), "KEY5"));

	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeReverseWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeSymmetricWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeDestroy(pTree);
	return 0;
}

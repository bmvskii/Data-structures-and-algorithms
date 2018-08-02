#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <cstring>

#include "tree_dynamic.hpp"

void PrintNodeLabel(const TreeNode & _node)
{
	std::cout << _node.m_label << ' ';
}

int main()
{
	Tree * pTree = TreeCreate("Mobile systems");

	TreeNode * pNodeA = TreeInsertChild(pTree->m_pRoot, "IOS");
	TreeNode * pNodeB = TreeInsertChild(pTree->m_pRoot, "Android");
	TreeNode * pNodeC = TreeInsertChild(pTree->m_pRoot, "Windows");

	TreeInsertChild(pNodeA, "11.0");
	TreeInsertChild(pNodeA, "10.0");
	TreeInsertChild(pNodeA, "9.0");

	TreeInsertChild(pNodeB, "Gingerbread");
	TreeInsertChild(pNodeB, "Ice Cream Sandwich	");
	TreeInsertChild(pNodeB, "Jelly Bean	");

	//checking out a root label of the tree. EXPECTED RESULT : "Mobile systems"
	assert(!strcmp(TreeGetRootNode(*pTree)->m_label, "Mobile systems"));

	//checking out a left most child label. EXPECTED RESULT : "Gingerbread"
	assert(!strcmp(TreeGetLeftMostChildNode(*pNodeB)->m_label, "Gingerbread"));

	//checking out a parent node label.  EXPECTED RESULT : "Mobile systems"
	assert(!strcmp(TreeGetParentNode(*pNodeC)->m_label, "Mobile systems"));

	//checking out a right sibling node label.  EXPECTED RESULT : "Windows"
	assert(!strcmp(TreeGetRightSiblingNode(*pNodeB)->m_label, "Windows"));
	
	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeReverseWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeSymmetricWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeDestroy(pTree);
	return 0;
}
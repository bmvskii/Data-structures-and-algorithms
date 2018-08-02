#include <iostream>
#include "bstree.hpp"

void printNode(const BSTree::Node & _node)
{
	std::cout << _node.m_key << std::endl;
}

int main()
{
	BSTree * pBST = BSTreeCreate();

	BSTreeInsertKey(*pBST, "Ivanov", 10);
	BSTreeInsertKey(*pBST, "Fedota", 5);
	BSTreeInsertKey(*pBST, "Bazilskiy", 3);
	BSTreeInsertKey(*pBST, "Docenko", 2);
	BSTreeInsertKey(*pBST, "Sergienko", 13);
	BSTreeInsertKey(*pBST, "Gomelev", 15);
	BSTreeInsertKey(*pBST, "Tishenko", 7);

	int command;
	char buffer[80];

	while (true)
	{
		std::cin >> command;
		std::cin.ignore();
		switch (command)
		{
		case 0: 
			BSTreeDestroy(pBST);
			return 0;
		case 1:
			BSTreeSymmetricWalk(*pBST, printNode);
			break;
		case 2:
			std::cin.getline(buffer, sizeof(buffer));
			if (BSTreeHasKey(*pBST, buffer))
				std::cout << BSTreeGetValue(*pBST, buffer) << std::endl;
			else
				std::cout << "Unknown student." << std::endl;
			break;
		case 3:
			std::cin.getline(buffer, sizeof(buffer));
			if (BSTreeHasKey(*pBST, buffer))
				BSTreeDeleteKey(*pBST, buffer);
			else
				std::cout << "Unknown student." << std::endl;
			break;
		default:
			std::cout << "Unknown command." << std::endl;
			break;
		}
	}


	BSTreeDestroy(pBST);
	return 0;
}
#include <iostream>
#include "bstree.hpp"

struct Runner {
	double m_time;
	char * m_name;
};

void printNode(const BSTree::Node & _pNode)
{
	std::cout << _pNode.m_key << " " << _pNode.m_value << std::endl;
}

int main()
{
	const int TOP_SIZE = 10;

	const Runner topRunners[TOP_SIZE] = {
		{9.58, "Usein Bolt"},
		{ 9.77, "Asafah Pauel" },
		{ 9.79, "Morris Green" },
		{ 9.84, "Donovan Bailey" },
		{ 9.85, "Lerroy Barrel" },
		{ 9.86, "Karl Luis" },
		{ 9.93, "Calvin Smith" },
		{ 10.00, "Armin Hurry" },
		{ 10.10, "Whillie Whilliams" },
		{ 10.20, "Jessey Owens" }
	};

	BSTree * topTenRunners = BSTreeCreate();

	for (int i = 0; i < TOP_SIZE; i++)
		BSTreeInsertKey(*topTenRunners, topRunners[i].m_time, topRunners[i].m_name);

	while (true)
	{
		char newRunnerNameBuffer[80];
		double newRunnerResultTime;

		std::cin >> newRunnerResultTime;
		std::cin.ignore();

		if (!newRunnerResultTime) return 0;

		std::cin.getline(newRunnerNameBuffer, sizeof(newRunnerNameBuffer));
	
		if (BSTreeHasKey(*topTenRunners, newRunnerResultTime))
			BSTreeInsertKey(*topTenRunners, newRunnerResultTime, newRunnerNameBuffer);

		else if (BSTreeMinimum(*topTenRunners) > newRunnerResultTime)
		{
			BSTreeDeleteKey(*topTenRunners, BSTreeMinimum(*topTenRunners));
			BSTreeInsertKey(*topTenRunners, newRunnerResultTime, newRunnerNameBuffer);
		}
		else
			std::cout << "Good luck, dude! Hope you'll get a valuable result soon." << std::endl;

		std::cout << std::endl << "TOP 10" << std::endl;
		BSTreeSymmetricWalk(*topTenRunners, printNode);
	}

	BSTreeDestroy(topTenRunners);
	return 0;
}
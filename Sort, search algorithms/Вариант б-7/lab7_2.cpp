#include <iostream>
#include "inch_priority_queue.hpp"
#include "inch_vector.hpp"

int main()
{
	InchPriorityQueue * pIPQ = InchPriorityQueueCreate();
	EnglishLengthUnit temp;

	while (std::cin)
	{
		std::cin >> temp.m_feet >> temp.m_inches;
		if (std::cin)
			InchPriorityQueueInsert(*pIPQ, temp);
	}

	InchPriorityQueuePrint(*pIPQ);

	InchPriorityQueueDestroy(pIPQ);
	return 0;
}

#include <iostream>
#include "double_priority_queue.hpp"

int main()
{
	DoublePriorityQueue * pq = DoublePriorityQueueCreate();

	double number;
	while (std::cin)
	{
		std::cin >> number;
		if (std::cin)
			if (number == 0)
			{
				if (!DoublePriorityQueueIsEmpty(*pq))
				{
					DoublePriorityQueueDeleteMax(*pq);
					if (!DoublePriorityQueueIsEmpty(*pq))
						std::cout << DoublePriorityQueueMax(*pq) << std::endl;
					else
						std::cout << "The queue is empty." << std::endl;
				}
				else
					std::cout << "Nothing to delete." << std::endl;
			}
			else
			{
				if (!DoublePriorityQueueIsEmpty(*pq))
					std::cout << DoublePriorityQueueMax(*pq) << std::endl;
				DoublePriorityQueueInsert(*pq, number);
			}
		else
			break;
	}

	DoublePriorityQueueDestroy(pq);
	return 0;
}
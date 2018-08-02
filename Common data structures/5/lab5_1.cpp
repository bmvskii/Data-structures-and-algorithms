#include <iostream>
#include "integer_queue.hpp"

int main()
{
	IntegerQueue * pQ = IntegerQueueCreate();

	int number ;

	do
	{
		std::cin >> number;

		if (number > 0)
			
				IntegerQueuePush(*pQ, number);
		else if (number == -1)
			if (IntegerQueueIsEmpty(*pQ))
				std::cout << "The queue is empty." << std::endl;
			else
				IntegerQueuePrint(*pQ, std::cout);
		else if (number == -2)
			if (!IntegerQueueIsEmpty(*pQ))
				IntegerQueuePop(*pQ);
			else
				std::cout << "The queue is empty." << std::endl;
	} while (number != 0);

	IntegerQueueDestroy(pQ);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>

#include "priority_queue.hpp"
#include "vector.hpp"
#include "test.hpp"

void runWithoutTest(int argc, char ** argv);
void runWithTest();

int main(int argc, char ** argv)
{
	if (argc == 2 && !_stricmp(argv[1], "test"))
		runWithTest();
	else
		runWithoutTest(argc, argv);
	return 0;
}

void runWithTest()
{
	testPriorityQueueWorking();
	testFunctional();
}

void runWithoutTest(int argc, char ** argv)
{
	int priorityQueueSize = atoi(argv[3]);
	PriorityQueue * pq = PriorityQueueCreate(priorityQueueSize);

	std::ifstream in(argv[1]);
	std::ofstream out(argv[2]);	char buffer[512];
	Payment p;

	while (!in.eof())
	{
		in.getline(buffer, sizeof(buffer));
		scanData(buffer, p, std::cout);
		PriorityQueueInsert(*pq, p);
	}

	PriorityQueuePrint(*pq, out);
	PriorityQueueDestroy(pq);
}
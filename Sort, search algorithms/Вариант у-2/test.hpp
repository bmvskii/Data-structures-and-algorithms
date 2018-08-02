#ifndef _TEST_HPP
#define _TEST_HPP

#include <iostream>
#include <cassert>
#include <fstream>

struct PriorityQueue;
struct Payment;

void testFunctional();

int scanData(char * _buffer, Payment & _p, std::ostream & _s);

void testPriorityQueueWorking();

#endif // !_TEST_HPP

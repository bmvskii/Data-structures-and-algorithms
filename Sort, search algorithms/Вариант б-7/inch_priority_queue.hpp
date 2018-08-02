#ifndef _INCH_PRIORITY_QUEUE_HPP_
#define _INCH_PRIORITY_QUEUE_HPP_

struct EnglishLengthUnit;

struct InchPriorityQueue;

InchPriorityQueue * InchPriorityQueueCreate();

void InchPriorityQueueDestroy(InchPriorityQueue * _pPQ);

void InchPriorityQueueClear(InchPriorityQueue & _pq);

bool InchPriorityQueueIsEmpty(const InchPriorityQueue & _pq);

void InchPriorityQueueInsert(InchPriorityQueue & _pq, EnglishLengthUnit _key);

EnglishLengthUnit InchPriorityQueueMin(const InchPriorityQueue & _pq);

void InchPriorityQueueDeleteMin(InchPriorityQueue & _pq);

void InchPriorityQueuePrint(const InchPriorityQueue & _pq);

#endif //  _INCH_PRIORITY_QUEUE_HPP_
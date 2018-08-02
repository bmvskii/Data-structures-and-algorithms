#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include <iostream>

struct PriorityQueue;
struct Payment;

PriorityQueue * PriorityQueueCreate (int _fixedSize);

void PriorityQueueDestroy ( PriorityQueue * _pPQ );

void PriorityQueueClear ( PriorityQueue & _pq );

bool PriorityQueueIsEmpty ( const PriorityQueue & _pq );

void PriorityQueueInsert ( PriorityQueue & _pq, Payment _key );

Payment PriorityQueueMin ( const PriorityQueue & _pq );

void PriorityQueueDeleteMin ( PriorityQueue & _pq );

void PriorityQueuePrint(const PriorityQueue &_pq, std::ostream & _s);

#endif //  _PRIORITY_QUEUE_HPP_

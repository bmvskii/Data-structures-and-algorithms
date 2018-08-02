#ifndef _DOUBLE_PRIORITY_QUEUE_HPP_
#define _DOUBLE_PRIORITY_QUEUE_HPP_

struct DoublePriorityQueue;

DoublePriorityQueue * DoublePriorityQueueCreate ();

void DoublePriorityQueueDestroy ( DoublePriorityQueue * _pPQ );

void DoublePriorityQueueClear ( DoublePriorityQueue & _pq );

bool DoublePriorityQueueIsEmpty ( const DoublePriorityQueue & _pq );

void DoublePriorityQueueInsert ( DoublePriorityQueue & _pq, double _key );

int DoublePriorityQueueMax ( const DoublePriorityQueue & _pq );

void DoublePriorityQueueDeleteMax ( DoublePriorityQueue & _pq );


#endif //  _DOUBLE_PRIORITY_QUEUE_HPP_

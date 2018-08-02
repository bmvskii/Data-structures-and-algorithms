#ifndef _DOUBLE_QUEUE_HPP_
#define _DOUBLE_QUEUE_HPP_

struct DoubleArrayQueue;

DoubleArrayQueue * DoubleArrayQueueCreate ();

DoubleArrayQueue * DoubleArrayQueueCreate ( int _fixedSize );

void DoubleArrayQueueDestroy ( DoubleArrayQueue * _pQueue );

void DoubleArrayQueueClear ( DoubleArrayQueue & _queue );

bool DoubleArrayQueueIsEmpty ( const DoubleArrayQueue & _queue );

bool DoubleArrayQueueIsFull ( const DoubleArrayQueue & _queue );

void DoubleArrayQueuePush ( DoubleArrayQueue & _queue, double * _value, int _size );

void DoubleArrayQueuePop ( DoubleArrayQueue & _queue );

double * DoubleArrayQueueFrontArray ( const DoubleArrayQueue & _queue );

int DoubleArrayQueueFrontSize(const DoubleArrayQueue & _queue);

#endif // _DOUBLE_QUEUE_HPP_
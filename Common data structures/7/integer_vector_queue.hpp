#ifndef _IntegerVector_VECTOR_QUEUE_HPP_
#define _IntegerVector_VECTOR_QUEUE_HPP_

struct IntegerVectorQueue;
struct IntegerVector;

IntegerVectorQueue * IntegerVectorQueueCreate ();

IntegerVectorQueue * IntegerVectorQueueCreate ( int _fixedSize );

void IntegerVectorQueueDestroy ( IntegerVectorQueue * _pQueue );

void IntegerVectorQueueClear ( IntegerVectorQueue & _queue );

bool IntegerVectorQueueIsEmpty ( const IntegerVectorQueue & _queue );

bool IntegerVectorQueueIsFull ( const IntegerVectorQueue & _queue );

void IntegerVectorQueuePush ( IntegerVectorQueue & _queue, IntegerVector & _value );

void IntegerVectorQueuePop ( IntegerVectorQueue & _queue );

IntegerVector & IntegerVectorQueueFront ( const IntegerVectorQueue & _queue );


#endif // _IntegerVector_VECTOR_QUEUE_HPP_
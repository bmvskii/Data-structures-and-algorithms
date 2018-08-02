#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_

struct IntegerDroppingQueue;

IntegerDroppingQueue * IntegerDroppingQueueCreate ();

IntegerDroppingQueue * IntegerDroppingQueueCreate ( int _fixedSize );

void IntegerDroppingQueueDestroy ( IntegerDroppingQueue * _pQueue );

void IntegerDroppingQueueClear ( IntegerDroppingQueue & _queue );

bool IntegerDroppingQueueIsEmpty ( const IntegerDroppingQueue & _queue );

bool IntegerDroppingQueueIsFull ( const IntegerDroppingQueue & _queue );

void IntegerDroppingQueuePush ( IntegerDroppingQueue & _queue, int _value );

void IntegerDroppingQueuePop ( IntegerDroppingQueue & _queue );

int IntegerDroppingQueueFront ( const IntegerDroppingQueue & _queue );


#endif // _INTEGER_QUEUE_HPP_
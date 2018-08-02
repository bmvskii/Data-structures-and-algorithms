#ifndef _POINT3D_QUEUE_HPP_
#define _POINT3D_QUEUE_HPP_

struct Point3D;
struct Point3DQueue;

Point3DQueue * Point3DQueueCreate ();

Point3DQueue * Point3DQueueCreate ( int _fixedSize );

void Point3DQueueDestroy ( Point3DQueue * _pQueue );

void Point3DQueueClear ( Point3DQueue & _queue );

bool Point3DQueueIsEmpty ( const Point3DQueue & _queue );

bool Point3DQueueIsFull ( const Point3DQueue & _queue );

void Point3DQueuePush ( Point3DQueue & _queue, Point3D _value );

void Point3DQueuePop ( Point3DQueue & _queue );

Point3D Point3DQueueFront ( const Point3DQueue & _queue );


#endif // _POINT3D_QUEUE_HPP_
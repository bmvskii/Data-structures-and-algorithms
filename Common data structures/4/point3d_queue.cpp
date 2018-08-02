#include "point3d_queue.hpp"
#include "point3d_list.hpp"

#include <cassert>


struct Point3DQueue
{
    Point3DList m_List;
};

Point3DQueue * Point3DQueueCreate ()
{
    Point3DQueue * pNewQueue = new Point3DQueue;
    Point3DListInit( pNewQueue->m_List );
    return pNewQueue;
}

void Point3DQueueDestroy ( Point3DQueue * _pQueue )
{
    Point3DListDestroy( _pQueue->m_List );
    delete _pQueue;
}

void Point3DQueueClear ( Point3DQueue & _queue )
{
    Point3DListDestroy( _queue.m_List );
}

bool Point3DQueueIsEmpty ( const Point3DQueue & _queue )
{
    return Point3DListIsEmpty( _queue.m_List );
}

bool Point3DQueueIsFull ( const Point3DQueue & _queue )
{
    return false;
}

void Point3DQueuePush ( Point3DQueue & _queue, Point3D _value )
{
    Point3DListPushBack( _queue.m_List, _value );
}

void Point3DQueuePop ( Point3DQueue & _queue )
{
    assert( ! Point3DQueueIsEmpty( _queue ) );
    Point3DListPopFront( _queue.m_List );
}

Point3D Point3DQueueFront ( const Point3DQueue & _queue )
{
    assert( ! Point3DQueueIsEmpty( _queue ) );
    return _queue.m_List.m_pFirst->m_value;
}

#include "integer_vector_queue.hpp"
#include "integer_vector_list.hpp"

#include <cassert>


struct IntegerVectorQueue
{
    IntegerVectorList m_List;
};

IntegerVectorQueue * IntegerVectorQueueCreate ()
{
    IntegerVectorQueue * pNewQueue = new IntegerVectorQueue;
    IntegerVectorListInit( pNewQueue->m_List );
    return pNewQueue;
}

void IntegerVectorQueueDestroy ( IntegerVectorQueue * _pQueue )
{
    IntegerVectorListDestroy( _pQueue->m_List );
    delete _pQueue;
}

void IntegerVectorQueueClear ( IntegerVectorQueue & _queue )
{
    IntegerVectorListDestroy( _queue.m_List );
}

bool IntegerVectorQueueIsEmpty ( const IntegerVectorQueue & _queue )
{
    return IntegerVectorListIsEmpty( _queue.m_List );
}

bool IntegerVectorQueueIsFull ( const IntegerVectorQueue & _queue )
{
    return false;
}

void IntegerVectorQueuePush ( IntegerVectorQueue & _queue, IntegerVector & _value )
{
    IntegerVectorListPushBack( _queue.m_List, _value );
}

void IntegerVectorQueuePop ( IntegerVectorQueue & _queue )
{
    assert( ! IntegerVectorQueueIsEmpty( _queue ) );
    IntegerVectorListPopFront( _queue.m_List );
}

IntegerVector & IntegerVectorQueueFront ( const IntegerVectorQueue & _queue )
{
    assert( ! IntegerVectorQueueIsEmpty( _queue ) );
    return _queue.m_List.m_pFirst->m_value;
}

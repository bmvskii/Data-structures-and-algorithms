#include "integer_queue.hpp"
#include <cassert>


struct IntegerDroppingQueue
{
    int * m_pData;
    int m_Size;
    int m_FrontIndex;
    int m_BackIndex;
};

IntegerDroppingQueue * IntegerDroppingQueueCreate ( int _fixedSize )
{
    assert( _fixedSize > 0 );
    
    IntegerDroppingQueue * pNewQueue = new IntegerDroppingQueue;
    
    pNewQueue->m_Size       = _fixedSize + 1;
    pNewQueue->m_pData      = new int[ pNewQueue->m_Size ];
    IntegerDroppingQueueClear( * pNewQueue );

    return pNewQueue;
}

void IntegerDroppingQueueDestroy ( IntegerDroppingQueue * _pQueue )
{
    delete[] _pQueue->m_pData;
    delete _pQueue;
}

void IntegerDroppingQueueClear ( IntegerDroppingQueue & _queue )
{
    _queue.m_FrontIndex = 0;
    _queue.m_BackIndex  = 0;
}

int IntegerDroppingQueueSize ( const IntegerDroppingQueue & _queue )
{
    // |-|-|-|-|-|-|        |-|-|-|-|-|-|  
    //   F     B                B     F

    return ( _queue.m_FrontIndex <= _queue.m_BackIndex ) ? 
               _queue.m_BackIndex - _queue.m_FrontIndex : 
               _queue.m_BackIndex + _queue.m_Size - _queue.m_FrontIndex;

}

bool IntegerDroppingQueueIsEmpty ( const IntegerDroppingQueue & _queue )
{
    return IntegerDroppingQueueSize( _queue ) == 0;
}

bool IntegerDroppingQueueIsFull ( const IntegerDroppingQueue & _queue )
{
    return IntegerDroppingQueueSize( _queue ) == ( _queue.m_Size - 1 );
}

int IntegerDroppingQueueNextIndex ( const IntegerDroppingQueue & _queue, int _index )
{
    int index  = _index + 1;
    if ( index == _queue.m_Size )
        index = 0;
    return index;
}

void IntegerDroppingQueuePush ( IntegerDroppingQueue & _queue, int _value )
{
	if (IntegerDroppingQueueIsFull(_queue))
		IntegerDroppingQueuePop(_queue);
    _queue.m_pData[ _queue.m_BackIndex ] = _value;
    _queue.m_BackIndex = IntegerDroppingQueueNextIndex( _queue, _queue.m_BackIndex );
}

void IntegerDroppingQueuePop ( IntegerDroppingQueue & _queue )
{
    assert( ! IntegerDroppingQueueIsEmpty( _queue ) );
    _queue.m_FrontIndex = IntegerDroppingQueueNextIndex( _queue, _queue.m_FrontIndex );
}

int IntegerDroppingQueueFront ( const IntegerDroppingQueue & _queue )
{
    assert( ! IntegerDroppingQueueIsEmpty( _queue ) );
    return _queue.m_pData[ _queue.m_FrontIndex ];
}

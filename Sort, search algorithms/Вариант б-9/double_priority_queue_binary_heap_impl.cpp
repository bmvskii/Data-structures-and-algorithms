#include "double_priority_queue.hpp"
#include "double_vector.hpp"

#include <cassert>
#include <iostream>


struct DoublePriorityQueue
{
	DoubleVector m_heapItems;
};


DoublePriorityQueue * DoublePriorityQueueCreate ()
{
	DoublePriorityQueue * pPQ = new DoublePriorityQueue;
	DoubleVectorInit( pPQ->m_heapItems );
	DoubleVectorPushBack( pPQ->m_heapItems, 0 ); // reserved cell
	return pPQ;
}


void DoublePriorityQueueDestroy ( DoublePriorityQueue * _pPQ )
{
	DoubleVectorDestroy( _pPQ->m_heapItems );
	delete _pPQ;
}



void DoublePriorityQueueClear ( DoublePriorityQueue & _pq )
{
	_pq.m_heapItems.m_nUsed = 1;
}


bool DoublePriorityQueueIsEmpty ( const DoublePriorityQueue & _pq )
{
	return _pq.m_heapItems.m_nUsed == 1;
}


void DoublePriorityQueueSwim ( DoublePriorityQueue & _pq, int _pos )
{
	double * pData = _pq.m_heapItems.m_pData;

	while ( _pos > 1 && ( pData[ _pos / 2 ] < pData[ _pos ] ) )
	{
		std::swap( pData[ _pos / 2 ], pData[ _pos ] );
		_pos = _pos / 2;
	}
}


void DoublePriorityQueueSink ( DoublePriorityQueue & _pq, int _pos )
{
	int maxPosition = _pq.m_heapItems.m_nUsed - 1;
	while ( 2 * _pos <= maxPosition )
	{
		int childPos = 2 * _pos;
		if ( childPos < maxPosition && _pq.m_heapItems.m_pData[ childPos ] < _pq.m_heapItems.m_pData[ childPos + 1 ] )
			++ childPos;

		if ( _pq.m_heapItems.m_pData[ _pos ] > _pq.m_heapItems.m_pData[ childPos ] )
			break;

		std::swap( _pq.m_heapItems.m_pData[ _pos ], _pq.m_heapItems.m_pData[ childPos ] );
		_pos = childPos;
	}
}


void DoublePriorityQueueInsert ( DoublePriorityQueue & _pq, double _key )
{
	DoubleVectorPushBack( _pq.m_heapItems, _key );
	DoublePriorityQueueSwim( _pq, _pq.m_heapItems.m_nUsed - 1 );
}


int DoublePriorityQueueMax ( const DoublePriorityQueue & _pq )
{
	assert( ! DoublePriorityQueueIsEmpty( _pq ) );
	return _pq.m_heapItems.m_pData[ 1 ];
}


void DoublePriorityQueueDeleteMax ( DoublePriorityQueue & _pq )
{
	assert( !DoublePriorityQueueIsEmpty( _pq ) );
	std::swap( _pq.m_heapItems.m_pData[ 1 ], _pq.m_heapItems.m_pData[ _pq.m_heapItems.m_nUsed - 1 ] );
	DoubleVectorPopBack( _pq.m_heapItems );
	DoublePriorityQueueSink( _pq, 1 );
}


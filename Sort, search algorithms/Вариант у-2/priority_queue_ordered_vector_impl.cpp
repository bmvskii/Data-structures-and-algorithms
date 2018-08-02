#include "priority_queue.hpp"
#include "vector.hpp"

#include <cassert>


struct PriorityQueue
{
	Vector m_orderedItems;
	int fixedSize;
};

PriorityQueue * PriorityQueueCreate (int _fixedSize)
{
	PriorityQueue * pPQ = new PriorityQueue;
	VectorInit( pPQ->m_orderedItems );
	pPQ->fixedSize = _fixedSize;
	return pPQ;
}


void PriorityQueueDestroy ( PriorityQueue * _pPQ )
{
	VectorDestroy( _pPQ->m_orderedItems );
	delete _pPQ;
}


void PriorityQueueClear ( PriorityQueue & _pq )
{
	VectorClear( _pq.m_orderedItems );
}


bool PriorityQueueIsEmpty ( const PriorityQueue & _pq )
{
	return _pq.m_orderedItems.m_nUsed == 0;
}

void PriorityQueueInsertInternal(PriorityQueue & _pq, Payment _key, int _position = -1)
{
	if (_position == -1)
		VectorPushBack(_pq.m_orderedItems, _key);
	else
		VectorInsertAt(_pq.m_orderedItems, _position, _key);
	
	if (_pq.fixedSize + 1 == _pq.m_orderedItems.m_nUsed)
		PriorityQueueDeleteMin(_pq);
}

void PriorityQueueInsert ( PriorityQueue & _pq, Payment _key)
{
	for ( int i = 0; i < _pq.m_orderedItems.m_nUsed; i++ )
		if ( _key.m_summary < _pq.m_orderedItems.m_pData[ i ].m_summary )
		{
			PriorityQueueInsertInternal(_pq, _key, i);
			return;
		}
		else if (_key.m_summary == _pq.m_orderedItems.m_pData[i].m_summary)
		{
			if (difftime(mktime(&_key.m_time),mktime(&_pq.m_orderedItems.m_pData[i].m_time)) <= 0)
			{
				PriorityQueueInsertInternal(_pq, _key, i);
				return;
			}
		}
	PriorityQueueInsertInternal(_pq, _key);
}

void showData(std::ostream & _s, Payment _p) {
	_s << _p.m_time.tm_mday << "/" << _p.m_time.tm_mon << "/" << _p.m_time.tm_year << " $"
		<< _p.m_summary << " " << _p.m_fstCompany << " " << _p.m_sndCompany << std::endl;
}

void PriorityQueuePrint(const PriorityQueue &_pq, std::ostream & _s)
{
	for (int i = _pq.m_orderedItems.m_nUsed - 1; i >= 0; i--)
		showData(_s, _pq.m_orderedItems.m_pData[i]);
}

Payment PriorityQueueMin ( const PriorityQueue & _pq )
{
	assert( ! PriorityQueueIsEmpty( _pq ) );
	return _pq.m_orderedItems.m_pData[ 0 ];
}


void PriorityQueueDeleteMin ( PriorityQueue & _pq )
{
	assert( !PriorityQueueIsEmpty( _pq ) );
	VectorDeleteAt( _pq.m_orderedItems, 0 );
}
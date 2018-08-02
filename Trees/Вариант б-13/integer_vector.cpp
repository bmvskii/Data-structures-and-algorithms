#include "integer_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void IntegerVectorInit ( IntegerVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new int[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void IntegerVectorDestroy ( IntegerVector & _vector )
{
    delete[] _vector.m_pData;
}


void IntegerVectorClear ( IntegerVector & _vector )
{
    _vector.m_nUsed = 0;
}


bool IntegerVectorIsEmpty ( const IntegerVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void IntegerVectorGrow ( IntegerVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    int * pNewData = new int[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof( int ) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void IntegerVectorPushBack ( IntegerVector & _vector, int _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        IntegerVectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed++ ] = _data;
}



void IntegerVectorPopBack ( IntegerVector & _vector )
{
    assert( ! IntegerVectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
}

void IntegerVectorPrint ( const IntegerVector & _vector, std::ostream & _stream, char _sep )
{
    for ( int i = 0; i < _vector.m_nUsed; i++ )
        _stream << _vector.m_pData[ i ] << _sep;
}

int IntegerVectorComparation(const IntegerVector & _lhs, const IntegerVector & _rhs)
{
	int minimum = 0;

	if (_lhs.m_nUsed < _rhs.m_nUsed)
		minimum = _lhs.m_nUsed;
	else
		minimum = _rhs.m_nUsed;

	for (int i = 0; i < minimum; i++)
		if (_lhs.m_pData[i] < _rhs.m_pData[i])		return 1;
		else if (_lhs.m_pData[i] > _rhs.m_pData[i]) return -1;

	if (_lhs.m_nUsed == minimum && _rhs.m_nUsed > _lhs.m_nUsed)		 return 1;
	else if (_rhs.m_nUsed == minimum && _lhs.m_nUsed > _rhs.m_nUsed) return -1;

	return 0;
}


void IntegerVectorInsertAt ( IntegerVector & _vector, int _position, int _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        IntegerVectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

    _vector.m_pData[ _position ] = _data;

    _vector.m_nUsed = newUsed;
}


void IntegerVectorDeleteAt ( IntegerVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

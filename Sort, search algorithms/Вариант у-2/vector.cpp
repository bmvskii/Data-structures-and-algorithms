#include "vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void VectorInit ( Vector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new Payment[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void VectorDestroy ( Vector & _vector )
{
    delete[] _vector.m_pData;
}


void VectorClear ( Vector & _vector )
{
    _vector.m_nUsed = 0;
}


bool VectorIsEmpty ( const Vector & _vector )
{
    return _vector.m_nUsed == 0;
}


void VectorGrow ( Vector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    Payment * pNewData = new Payment[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof( Payment ) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void VectorPushBack ( Vector & _vector, Payment _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        VectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed++ ] = _data;
}



void VectorPopBack ( Vector & _vector )
{
    assert( ! VectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
}

void VectorInsertAt ( Vector & _vector, int _position, Payment _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        VectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

    _vector.m_pData[ _position ] = _data;

    _vector.m_nUsed = newUsed;
}


void VectorDeleteAt ( Vector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

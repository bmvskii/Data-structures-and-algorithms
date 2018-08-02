#include "inch_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void InchVectorInit ( InchVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new EnglishLengthUnit[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void InchVectorDestroy ( InchVector & _vector )
{
    delete[] _vector.m_pData;
}


void InchVectorClear ( InchVector & _vector )
{
    _vector.m_nUsed = 0;
}


bool InchVectorIsEmpty ( const InchVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void InchVectorGrow ( InchVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    EnglishLengthUnit * pNewData = new EnglishLengthUnit[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof( EnglishLengthUnit ) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void InchVectorPushBack ( InchVector & _vector, EnglishLengthUnit _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        InchVectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed++ ] = _data;
}



void InchVectorPopBack ( InchVector & _vector )
{
    assert( ! InchVectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
}


void InchVectorInsertAt ( InchVector & _vector, int _position, EnglishLengthUnit _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        InchVectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

    _vector.m_pData[ _position ] = _data;

    _vector.m_nUsed = newUsed;
}


void InchVectorDeleteAt ( InchVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

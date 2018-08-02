#include "double_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void DoubleVectorInit ( DoubleVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new double[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void DoubleVectorDestroy ( DoubleVector & _vector )
{
    delete[] _vector.m_pData;
}


void DoubleVectorClear ( DoubleVector & _vector )
{
    _vector.m_nUsed = 0;
}


bool DoubleVectorIsEmpty ( const DoubleVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void DoubleVectorGrow ( DoubleVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    double * pNewData = new double[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof(double) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void DoubleVectorPushBack ( DoubleVector & _vector, double _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        DoubleVectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed++ ] = _data;
}



void DoubleVectorPopBack ( DoubleVector & _vector )
{
    assert( ! DoubleVectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
}


void DoubleVectorRead ( DoubleVector & _vector, std::istream & _stream )
{
    while ( true )
    {
        double temp;
        _stream >> temp;
        if ( _stream )
            DoubleVectorPushBack( _vector, temp );
        else
            break;
    }    
}


void DoubleVectorReadTillZero ( DoubleVector & _vector, std::istream & _stream )
{
    while ( true )
    {
        double temp;
        _stream >> temp;
        if ( _stream && temp != 0 )
            DoubleVectorPushBack( _vector, temp );
        else
            break;
    }
}


void DoubleVectorPrint ( const DoubleVector & _vector, std::ostream & _stream, char _sep )
{
    for ( int i = 0; i < _vector.m_nUsed; i++ )
        _stream << _vector.m_pData[ i ] << _sep;
}


void DoubleVectorInsertAt ( DoubleVector & _vector, int _position, double _data )
{
    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        DoubleVectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

    _vector.m_pData[ _position ] = _data;

    _vector.m_nUsed = newUsed;
}


void DoubleVectorDeleteAt ( DoubleVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

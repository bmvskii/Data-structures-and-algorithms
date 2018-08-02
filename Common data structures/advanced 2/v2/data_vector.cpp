#define _CRT_SECURE_NO_WARNINGS
#include "data_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void DataVectorInit ( DataVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new Data[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void DataVectorDestroy ( DataVector & _vector )
{
    delete[] _vector.m_pData;
}


void DataVectorClear ( DataVector & _vector )
{
    _vector.m_nUsed = 0;
}


bool DataVectorIsEmpty ( const DataVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void DataVectorGrow ( DataVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    Data * pNewData = new Data[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof( Data ) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}

void DataVectorPushBack ( DataVector & _vector, Data _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        DataVectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed].m_personAge = _data.m_personAge;
	_vector.m_pData[_vector.m_nUsed].m_personSecondName = new char[strlen(_data.m_personSecondName) + 1];
	strcpy(_vector.m_pData[_vector.m_nUsed++].m_personSecondName, _data.m_personSecondName);
}

void DataVectorPopBack ( DataVector & _vector )
{
    assert( ! DataVectorIsEmpty( _vector ) );

	delete[]_vector.m_pData[_vector.m_nUsed - 1].m_personSecondName;
    -- _vector.m_nUsed;
}

void DataVectorInsertAt ( DataVector & _vector, int _position, Data _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        DataVectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

	_vector.m_pData[_position].m_personAge = _data.m_personAge;
	_vector.m_pData[_position].m_personSecondName = new char[strlen(_data.m_personSecondName) + 1];
	strcpy(_vector.m_pData[_position].m_personSecondName, _data.m_personSecondName);

    _vector.m_nUsed = newUsed;
}


void DataVectorDeleteAt ( DataVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

	delete[]_vector.m_pData[_position].m_personSecondName;
    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

void DataVectorPrintFixed(const DataVector & _vector, std::ostream & _stream, int _age)
{
	for (int i = 0; i < _vector.m_nUsed; i++)
		if (_vector.m_pData[i].m_personAge > _age)
			_stream << _vector.m_pData[i].m_personSecondName << " "
			<< _vector.m_pData[i].m_personAge << std::endl;
}
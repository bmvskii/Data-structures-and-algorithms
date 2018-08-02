#define _CRT_SECURE_NO_WARNINGS
#include "string_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void StringVectorInit ( StringVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new char*[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void StringVectorDestroy ( StringVector & _vector )
{
	for (int i = 0; i < _vector.m_nUsed; i++)
		delete[]_vector.m_pData[i];
    delete[] _vector.m_pData;
}


void StringVectorClear ( StringVector & _vector )
{
	for (int i = 0; i < _vector.m_nUsed; i++)
		delete[]_vector.m_pData[i];
    _vector.m_nUsed = 0;
}


bool StringVectorIsEmpty ( const StringVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void StringVectorGrow ( StringVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    char ** pNewData = new char*[ nAllocatedNew ];
	
	for (int i = 0; i < _vector.m_nUsed; i++)
	{
		pNewData[i] = new char[strlen(_vector.m_pData[i]) + 1];
		strcpy(pNewData[i], _vector.m_pData[i]);
	}

	for (int i = 0; i < _vector.m_nUsed; i++)
		delete[]_vector.m_pData[i];
    delete[] _vector.m_pData;

    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void StringVectorPushBack ( StringVector & _vector, const char * _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        StringVectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed] = new char[strlen(_data)+1];
	strcpy(_vector.m_pData[_vector.m_nUsed++], _data);
}



void StringVectorPopBack ( StringVector & _vector )
{
    assert( ! StringVectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
	delete[]_vector.m_pData[_vector.m_nUsed];
}

void StringVectorPrint ( const StringVector & _vector, std::ostream & _stream, char _sep )
{
    for ( int i = 0; i < _vector.m_nUsed; i++ )
        _stream << _vector.m_pData[ i ] << _sep;
}


void StringVectorInsertAt ( StringVector & _vector, int _position, const char * _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        StringVectorGrow( _vector );

    for ( int i = _vector.m_nUsed-1; i > _position; i-- )
        strcpy(_vector.m_pData[ i ],_vector.m_pData[ i - 1]);

	_vector.m_pData[_position] = new char[strlen(_data) + 1];
	strcpy(_vector.m_pData[_position], _data);

    _vector.m_nUsed = newUsed;
}


void StringVectorDeleteAt ( StringVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
       strcpy(_vector.m_pData[ i - 1 ], _vector.m_pData[ i ]);

    -- _vector.m_nUsed;
	delete[]_vector.m_pData[_vector.m_nUsed];
}

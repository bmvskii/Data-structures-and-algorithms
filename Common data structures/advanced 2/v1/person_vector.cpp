#define _CRT_SECURE_NO_WARNINGS
#include "person_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void VectorInit ( Vector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new Person[ _allocatedSize ];
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
    Person * pNewData = new Person[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof( Person ) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}

void VectorParseData(Vector & _vector, char * _data)
{
	Person newPerson;
	char * copy = new char[strlen(_data) + 1];
	strcpy(copy, _data);

	char * pCurrent = strtok(copy, " ");
	newPerson.m_name = new char[strlen(pCurrent) + 1];
	strcpy(newPerson.m_name, pCurrent);

	pCurrent = strtok(NULL, " ");
	if (atoi(pCurrent))
		newPerson.m_age = atoi(pCurrent);
	else {
		std::cout << "Wrong format of data. It should be a number." << std::endl;
		std::cout << "Your data : " << pCurrent << std::endl;
		return;
	}
		
	VectorPushBack(_vector, newPerson);
}

void VectorPushBack ( Vector & _vector, Person _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        VectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed].m_age = _data.m_age;
	_vector.m_pData[_vector.m_nUsed].m_name = new char[strlen(_data.m_name) + 1];
	strcpy(_vector.m_pData[_vector.m_nUsed++].m_name, _data.m_name);
}

void VectorPopBack ( Vector & _vector )
{
    assert( ! VectorIsEmpty( _vector ) );

	delete[]_vector.m_pData[_vector.m_nUsed - 1].m_name;
    -- _vector.m_nUsed;
}

void VectorInsertAt ( Vector & _vector, int _position, Person _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        VectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

	_vector.m_pData[_position].m_age = _data.m_age;
	_vector.m_pData[_position].m_name = new char[strlen(_data.m_name) + 1];
	strcpy(_vector.m_pData[_position].m_name, _data.m_name);

    _vector.m_nUsed = newUsed;
}


void VectorDeleteAt ( Vector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

	delete[]_vector.m_pData[_position].m_name;
    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

void VectorFixedShow(const Vector & _vector, std::ostream & _stream, int _fixedAge)
{
	for (int i = 0; i < _vector.m_nUsed; i++)
		if (_vector.m_pData[i].m_age > _fixedAge)
			_stream << _vector.m_pData[i].m_name << " " << _vector.m_pData[i].m_age << std::endl;
}
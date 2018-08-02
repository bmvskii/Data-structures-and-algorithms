#ifndef _PERSON_VECTOR_HPP_
#define _PERSON_VECTOR_HPP_

#include <iostream>

struct Person
{
	char * m_name;
	int m_age;
};

struct Vector
{
	Person * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void VectorInit ( Vector & _vector, int _allocatedSize = 10 );

void VectorDestroy ( Vector & _vector );

void VectorClear ( Vector & _vector );

bool VectorIsEmpty ( const Vector & _vector );

void VectorPushBack ( Vector & _vector, Person _data );

void VectorPopBack ( Vector & _vector );

void VectorInsertAt ( Vector & _vector, int _position, Person _data );

void VectorDeleteAt ( Vector & _vector, int _position );

void VectorParseData(Vector & _vector, char * _data);

void VectorFixedShow(const Vector & _vector, std::ostream & _stream, int _fixedAge);

#endif //  _PERSON_VECTOR_HPP_

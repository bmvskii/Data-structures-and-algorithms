#ifndef _INTEGER_VECTOR_HPP_
#define _INTEGER_VECTOR_HPP_

#include <iostream>

struct Account {
	int m_ID;
	double m_summary;
};

struct Vector
{
    Account * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void VectorInit ( Vector & _vector, int _allocatedSize = 10 );

void VectorDestroy ( Vector & _vector );

void VectorClear ( Vector & _vector );

bool VectorIsEmpty ( const Vector & _vector );

void VectorPushBack ( Vector & _vector, Account _data );

void VectorPopBack ( Vector & _vector );

void VectorInsertAt ( Vector & _vector, int _position, Account _data );

void VectorDeleteAt ( Vector & _vector, int _position );

void VectorPrint ( const Vector & _vector, std::ostream & _stream);


#endif //  _INTEGER_VECTOR_HPP_

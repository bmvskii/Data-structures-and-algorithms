#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <ctime>

struct Payment
{
	char * m_fstCompany;
	char * m_sndCompany;
	double m_summary;
	tm m_time;
};

struct Vector
{
    Payment * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void VectorInit ( Vector & _vector, int _allocatedSize = 10 );

void VectorDestroy ( Vector & _vector );

void VectorClear ( Vector & _vector );

bool VectorIsEmpty ( const Vector & _vector );

void VectorPushBack ( Vector & _vector, Payment _data );

void VectorPopBack ( Vector & _vector );

void VectorInsertAt ( Vector & _vector, int _position, Payment _data );

void VectorDeleteAt ( Vector & _vector, int _position );

#endif //  _VECTOR_HPP_

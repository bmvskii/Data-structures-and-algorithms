#ifndef _INCH_VECTOR_HPP_
#define _INCH_VECTOR_HPP_

#include <iostream>

struct EnglishLengthUnit
{
	short m_feet;
	short m_inches;
};

struct InchVector
{
    EnglishLengthUnit * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void InchVectorInit ( InchVector & _vector, int _allocatedSize = 10 );

void InchVectorDestroy ( InchVector & _vector );

void InchVectorClear ( InchVector & _vector );

bool InchVectorIsEmpty ( const InchVector & _vector );

void InchVectorPushBack ( InchVector & _vector, EnglishLengthUnit _data );

void InchVectorPopBack ( InchVector & _vector );

void InchVectorInsertAt ( InchVector & _vector, int _position, EnglishLengthUnit _data );

void InchVectorDeleteAt(InchVector & _vector, int _position);

#endif //  _INCH_VECTOR_HPP_

#ifndef _INTEGER_VECTOR_HPP_
#define _INTEGER_VECTOR_HPP_

#include <iostream>


struct IntegerVector
{
    int * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void IntegerVectorInit ( IntegerVector & _vector, int _allocatedSize = 10 );

void IntegerVectorDestroy ( IntegerVector & _vector );

void IntegerVectorClear ( IntegerVector & _vector );

bool IntegerVectorIsEmpty ( const IntegerVector & _vector );

void IntegerVectorPushBack ( IntegerVector & _vector, int _data );

void IntegerVectorPopBack ( IntegerVector & _vector );

void IntegerVectorInsertAt ( IntegerVector & _vector, int _position, int _data );

void IntegerVectorDeleteAt ( IntegerVector & _vector, int _position );

void IntegerVectorPrint ( const IntegerVector & _vector, std::ostream & _stream, char _sep = ' ' );

void IntegerVectorCopy(IntegerVector & _lhs, const IntegerVector & _rhs);

int IntegerVectorComparation(const IntegerVector & _lhs, const IntegerVector & _rhs);

#endif //  _INTEGER_VECTOR_HPP_

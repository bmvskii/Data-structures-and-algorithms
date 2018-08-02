#ifndef _DOUBLE_VECTOR_HPP_
#define _DOUBLE_VECTOR_HPP_

#include <iostream>


struct DoubleVector
{
    double * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void DoubleVectorInit ( DoubleVector & _vector, int _allocatedSize = 10 );

void DoubleVectorDestroy ( DoubleVector & _vector );

void DoubleVectorClear ( DoubleVector & _vector );

bool DoubleVectorIsEmpty ( const DoubleVector & _vector );

void DoubleVectorPushBack ( DoubleVector & _vector, double _data );

void DoubleVectorPopBack ( DoubleVector & _vector );

void DoubleVectorInsertAt ( DoubleVector & _vector, int _position, double _data );

void DoubleVectorDeleteAt ( DoubleVector & _vector, int _position );

void DoubleVectorRead ( DoubleVector & _vector, std::istream & _stream );

void DoubleVectorReadTillZero ( DoubleVector & _vector, std::istream & _stream );

void DoubleVectorPrint ( const DoubleVector & _vector, std::ostream & _stream, char _sep = ' ' );


#endif //  _DOUBLE_VECTOR_HPP_
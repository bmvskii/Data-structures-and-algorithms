#ifndef _INTEGER_VECTOR_HPP_
#define _INTEGER_VECTOR_HPP_

#include <iostream>


struct IntegerVector
{
	struct Cell
	{
		int m_key;
		int m_value;
	};
	Cell * m_pData;
	int m_nUsed;
	int m_nAllocated;
};


void IntegerVectorInit(IntegerVector & _vector, int _allocatedSize = 10);

void IntegerVectorDestroy(IntegerVector & _vector);

void IntegerVectorClear(IntegerVector & _vector);

bool IntegerVectorIsEmpty(const IntegerVector & _vector);

void IntegerVectorPushBack(IntegerVector & _vector, int _key, int _value);

void IntegerVectorPopBack(IntegerVector & _vector);

void IntegerVectorInsertAt(IntegerVector & _vector, int _position, int _key , int _value);

void IntegerVectorDeleteAt(IntegerVector & _vector, int _position);


#endif //  _INTEGER_VECTOR_HPP_
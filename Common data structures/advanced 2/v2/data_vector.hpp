#ifndef _DATA_VECTOR_HPP_
#define _DATA_VECTOR_HPP_

#include <iostream>

struct Data
{
	char * m_personSecondName;
	int m_personAge;
};

struct DataVector
{
	Data * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void DataVectorInit ( DataVector & _vector, int _allocatedSize = 10 );

void DataVectorDestroy ( DataVector & _vector );

void DataVectorClear ( DataVector & _vector );

bool DataVectorIsEmpty ( const DataVector & _vector );

void DataVectorPushBack ( DataVector & _vector, Data _data );

void DataVectorPopBack ( DataVector & _vector );

void DataVectorInsertAt ( DataVector & _vector, int _position, Data _data );

void DataVectorDeleteAt ( DataVector & _vector, int _position );

void DataVectorPrintFixed(const DataVector & _vector, std::ostream & _stream, int _age);

#endif //  _DATA_VECTOR_HPP_

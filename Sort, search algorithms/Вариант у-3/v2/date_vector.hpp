#ifndef _DATE_VECTOR_HPP_
#define _DATE_VECTOR_HPP_

#include <iostream>

struct Date {
	int m_day, m_month, m_year;
};

struct DateVector
{
    Date * m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void DateVectorInit ( DateVector & _vector, int _allocatedSize = 10 );

void DateVectorDestroy ( DateVector & _vector );

void DateVectorClear ( DateVector & _vector );

bool DateVectorIsEmpty ( const DateVector & _vector );

void DateVectorPushBack ( DateVector & _vector, Date _data, int & _pos );

void DateVectorPopBack ( DateVector & _vector );

void DateVectorInsertAt ( DateVector & _vector, int _position, Date _data );

void DateVectorDeleteAt ( DateVector & _vector, int _position );

#endif //  _DATE_VECTOR_HPP_

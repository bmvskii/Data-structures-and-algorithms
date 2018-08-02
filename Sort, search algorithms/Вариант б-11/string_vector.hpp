#ifndef _STRING_VECTOR_HPP_
#define _STRING_VECTOR_HPP_

#include <iostream>


struct StringVector
{
    char ** m_pData;
    int m_nUsed;
    int m_nAllocated;
};


void StringVectorInit ( StringVector & _vector, int _allocatedSize = 10 );

void StringVectorDestroy ( StringVector & _vector );

void StringVectorClear ( StringVector & _vector );

bool StringVectorIsEmpty ( const StringVector & _vector );

void StringVectorPushBack ( StringVector & _vector, const char * _data );

void StringVectorPopBack ( StringVector & _vector );

void StringVectorInsertAt ( StringVector & _vector, int _position, const char * _data );

void StringVectorDeleteAt ( StringVector & _vector, int _position );

void StringVectorPrint ( const StringVector & _vector, std::ostream & _stream, char _sep = ' ' );


#endif //  _STRING_VECTOR_HPP_

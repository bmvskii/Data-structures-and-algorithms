#ifndef _INTEGER_VECTOR_LIST_HPP_
#define _INTEGER_VECTOR_LIST_HPP_

#include <iostream>
#include "integer_vector.hpp"

struct IntegerVectorList
{
    struct Node
    {
        IntegerVector m_value;
        Node * m_pNext;
    };

    Node * m_pFirst, * m_pLast;
};


void IntegerVectorListInit ( IntegerVectorList & _list );

void IntegerVectorListDestroy ( IntegerVectorList & _list );

bool IntegerVectorListIsEmpty ( const IntegerVectorList & _list );

int IntegerVectorListSize ( const IntegerVectorList & _list );

void IntegerVectorListClear ( IntegerVectorList & _list );

void IntegerVectorListPushBack ( IntegerVectorList & _list, IntegerVector _data );

void IntegerVectorListPushFront ( IntegerVectorList & _list, IntegerVector _data );

void IntegerVectorListInsertAfter ( IntegerVectorList & _list, IntegerVectorList::Node * _pPrevNode, IntegerVector _data );

void IntegerVectorListInsertBefore ( IntegerVectorList & _list, IntegerVectorList::Node * _pNextNode, IntegerVector _data );

void IntegerVectorListPopBack ( IntegerVectorList & _list );

void IntegerVectorListPopFront ( IntegerVectorList & _list );

void IntegerVectorListDeleteAfter ( IntegerVectorList & _list, IntegerVectorList::Node * _pPrevNode );

void IntegerVectorListDeleteBefore ( IntegerVectorList & _list, IntegerVectorList::Node * _pNextNode );

void IntegerVectorListDeleteNode ( IntegerVectorList & _list, IntegerVectorList::Node * _pNode );



#endif //  _INTEGER_VECTOR_FORWARD_LIST_HPP_
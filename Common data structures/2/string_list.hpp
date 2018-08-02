#ifndef _STRING_LIST_HPP_
#define _STRING_LIST_HPP_

#include <iostream>


struct StringList
{
    struct Node
    {
        char * m_value;
        Node * m_pNext;
    };

    Node * m_pFirst, * m_pLast;
};


void StringListInit ( StringList & _list );

void StringListDestroy ( StringList & _list );

bool StringListIsEmpty ( const StringList & _list );

int StringListSize ( const StringList & _list );

void StringListClear ( StringList & _list );

void StringListPushBack ( StringList & _list, const char * _data );

void StringListPushFront ( StringList & _list, const char * _data );

void StringListInsertAfter ( StringList & _list, StringList::Node * _pPrevNode, const char * _data );

void StringListInsertBefore ( StringList & _list, StringList::Node * _pNextNode, const char * _data );

void StringListPopBack ( StringList & _list );

void StringListPopFront ( StringList & _list );

void StringListDeleteAfter ( StringList & _list, StringList::Node * _pPrevNode );

void StringListDeleteBefore ( StringList & _list, StringList::Node * _pNextNode );

void StringListDeleteNode ( StringList & _list, StringList::Node * _pNode );

void StringListRead ( StringList & _list, std::istream & _i );

void StringListPrint ( const StringList & _list, std::ostream & _o, char _sep = ' ' );

#endif //  _STRING_FORWARD_LIST_HPP_
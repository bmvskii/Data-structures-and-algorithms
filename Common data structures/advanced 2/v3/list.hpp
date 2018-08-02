#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <iostream>

struct Human
{
	int m_age;
	char * m_sename;
};

struct List
{
    struct Node
    {
        Human m_value;
        Node * m_pNext;
    };

    Node * m_pFirst, * m_pLast;
};


void ListInit ( List & _list );

void ListDestroy ( List & _list );

bool ListIsEmpty ( const List & _list );

int ListSize ( const List & _list );

void ListClear ( List & _list );

void ListPushBack ( List & _list, Human _data );

void ListPushFront ( List & _list, Human _data );

void ListInsertAfter ( List & _list, List::Node * _pPrevNode, Human _data );

void ListInsertBefore ( List & _list, List::Node * _pNextNode, Human _data );

void ListPopBack ( List & _list );

void ListPopFront ( List & _list );

void ListDeleteAfter ( List & _list, List::Node * _pPrevNode );

void ListDeleteBefore ( List & _list, List::Node * _pNextNode );

void ListDeleteNode ( List & _list, List::Node * _pNode );

void ListPrint( const List & _list, std::ostream & _o, int _age);

#endif //  _FORWARD_LIST_HPP_
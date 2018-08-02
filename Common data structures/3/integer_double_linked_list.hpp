#ifndef _INTEGER_LIST_HPP_
#define _INTEGER_LIST_HPP_

#include <iostream>


struct IntegerDoubleLinkedList
{
	struct Node
	{
		int m_value;
		Node * m_pNext;
		Node * previous;
	};

	Node * m_pFirst, *m_pLast;
};

bool IntegerDoubleLinkedListIsEmpty(const IntegerDoubleLinkedList & _list);

int IntegerDoubleLinkedListSize(const IntegerDoubleLinkedList & _list);

void IntegerDoubleLinkedListClear(IntegerDoubleLinkedList & _list);

void IntegerDoubleLinkedListInit(IntegerDoubleLinkedList & _list);

void IntegerDoubleLinkedListDestroy(IntegerDoubleLinkedList & _list);

void IntegerDoubleLinkedListPushBack(IntegerDoubleLinkedList & _list, int _data);

void IntegerDoubleLinkedListPushFront(IntegerDoubleLinkedList & _list, int _data);

void IntegerDoubleLinkedListInsertAfter(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pPrevNode, int _data);

void IntegerDoubleLinkedListInsertBefore(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pNextNode, int _data);

void IntegerDoubleLinkedListPopBack(IntegerDoubleLinkedList & _list);

void IntegerDoubleLinkedListPopFront(IntegerDoubleLinkedList & _list);

void IntegerDoubleLinkedListDeleteAfter(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pPrevNode);

void IntegerDoubleLinkedListDeleteBefore(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pNextNode);

void IntegerDoubleLinkedListDeleteNode(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pNode);

void IntegerDoubleLinkedListRead(IntegerDoubleLinkedList & _list, std::istream & _i);

void IntegerDoubleLinkedListReadTillZero(IntegerDoubleLinkedList & _list, std::istream & _i);

void IntegerDoubleLinkedListPrint(IntegerDoubleLinkedList const & _list, std::ostream & _stream, int mode = 0);

#endif //  _INTEGER_FORWARD_LIST_HPP_
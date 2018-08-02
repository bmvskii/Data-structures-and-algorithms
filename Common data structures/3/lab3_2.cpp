#include <iostream>
#include "integer_double_linked_list.hpp"
#include <cassert>

int main()
{
	IntegerDoubleLinkedList list;
	IntegerDoubleLinkedListInit(list);

	IntegerDoubleLinkedListPushBack(list, 1);
	IntegerDoubleLinkedListPushBack(list, 2);
	IntegerDoubleLinkedListPushBack(list, 3);
	IntegerDoubleLinkedListPushBack(list, 4);

	IntegerDoubleLinkedList::Node * pLast = list.m_pLast;
	assert(pLast->m_value == 4);
	assert(pLast->previous->m_value == 3);
	
	IntegerDoubleLinkedList::Node * pFirst = list.m_pFirst;
	assert(pFirst->m_pNext->m_value == 2);

	IntegerDoubleLinkedList::Node * pNode = list.m_pFirst->m_pNext;
	assert(pNode->previous->m_value == 1);

	IntegerDoubleLinkedListDestroy(list);
	return 0;
}
#include "integer_double_linked_list.hpp"
#include <cassert>

void IntegerDoubleLinkedListInit(IntegerDoubleLinkedList & _list)
{
	_list.m_pFirst = _list.m_pLast = nullptr;
}


void IntegerDoubleLinkedListDestroy(IntegerDoubleLinkedList & _list)
{
	IntegerDoubleLinkedListClear(_list);
}


void IntegerDoubleLinkedListClear(IntegerDoubleLinkedList & _list)
{
	IntegerDoubleLinkedList::Node * pCurrent = _list.m_pFirst;
	while (pCurrent)
	{
		IntegerDoubleLinkedList::Node * pTemp = pCurrent->m_pNext;
		delete pCurrent;
		pCurrent = pTemp;
	}

	_list.m_pFirst = _list.m_pLast = nullptr;
}


bool IntegerDoubleLinkedListIsEmpty(const IntegerDoubleLinkedList & _list)
{
	return _list.m_pFirst == nullptr;
}


int IntegerDoubleLinkedListSize(const IntegerDoubleLinkedList & _list)
{
	int nElements = 0;
	const IntegerDoubleLinkedList::Node * pNode = _list.m_pFirst;
	while (pNode)
	{
		++nElements;
		pNode = pNode->m_pNext;
	}

	return nElements;
}


void IntegerDoubleLinkedListPushBack(IntegerDoubleLinkedList & _list, int _data)
{
	IntegerDoubleLinkedList::Node * pNewNode = new IntegerDoubleLinkedList::Node;
	pNewNode->m_value = _data;
	pNewNode->m_pNext = nullptr;
	pNewNode->previous = nullptr;

	if (!_list.m_pFirst)
	{
		assert(!_list.m_pLast);
		_list.m_pFirst = pNewNode;
	}
	else {
		pNewNode->previous = _list.m_pLast;
		_list.m_pLast->m_pNext = pNewNode;
	}

	_list.m_pLast = pNewNode;
}

void IntegerDoubleLinkedListPushFront(IntegerDoubleLinkedList & _list, int _data)
{
	IntegerDoubleLinkedList::Node * pNewNode = new IntegerDoubleLinkedList::Node;
	pNewNode->m_value = _data;
	pNewNode->m_pNext = _list.m_pFirst;
	pNewNode->previous = nullptr;

	_list.m_pFirst = pNewNode;

	if (!_list.m_pLast) {
		pNewNode->previous = _list.m_pFirst;
		_list.m_pLast = pNewNode;
	}
}


void IntegerDoubleLinkedListInsertAfter(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pPrevNode, int _data)
{
	assert(!IntegerDoubleLinkedListIsEmpty(_list));

	if (_pPrevNode == _list.m_pLast)
		IntegerDoubleLinkedListPushBack(_list, _data);

	else
	{
		IntegerDoubleLinkedList::Node * pNewNode = new IntegerDoubleLinkedList::Node;
		pNewNode->m_value = _data;
		pNewNode->m_pNext = _pPrevNode->m_pNext;
		pNewNode->previous = _pPrevNode;
		_pPrevNode->m_pNext = pNewNode;
	}
}


void IntegerDoubleLinkedListInsertBefore(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pNextNode, int _data)
{
	assert(!IntegerDoubleLinkedListIsEmpty(_list));

	if (_pNextNode == _list.m_pFirst)
		IntegerDoubleLinkedListPushFront(_list, _data);

	else
	{
		IntegerDoubleLinkedList::Node * pCurrent = _list.m_pFirst;
		while (pCurrent && pCurrent->m_pNext != _pNextNode)
			pCurrent = pCurrent->m_pNext;

		assert(pCurrent);

		IntegerDoubleLinkedList::Node * pNewNode = new IntegerDoubleLinkedList::Node;
		pNewNode->m_value = _data;

		pNewNode->m_pNext = _pNextNode;

		pCurrent->m_pNext = pNewNode;

	}
}


void IntegerDoubleLinkedListPopFront(IntegerDoubleLinkedList & _list)
{
	assert(!IntegerDoubleLinkedListIsEmpty(_list));

	IntegerDoubleLinkedList::Node * pFirst = _list.m_pFirst;

	if (_list.m_pFirst == _list.m_pLast)
		_list.m_pFirst = _list.m_pLast = nullptr;

	else
		_list.m_pFirst = pFirst->m_pNext;

	delete pFirst;
}


void IntegerDoubleLinkedListPopBack(IntegerDoubleLinkedList & _list)
{
	assert(!IntegerDoubleLinkedListIsEmpty(_list));

	IntegerDoubleLinkedList::Node * pLast = _list.m_pLast;

	if (_list.m_pFirst == _list.m_pLast)
		_list.m_pFirst = _list.m_pLast = nullptr;

	else
	{
		IntegerDoubleLinkedList::Node * pCurrent = _list.m_pFirst;
		while (pCurrent->m_pNext != _list.m_pLast)
			pCurrent = pCurrent->m_pNext;

		_list.m_pLast = pCurrent;
		pCurrent->m_pNext = nullptr;
	}

	delete pLast;
}


void IntegerDoubleLinkedListDeleteAfter(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pPrevNode)
{
	assert(!IntegerDoubleLinkedListIsEmpty(_list));

	assert(_list.m_pLast != _pPrevNode);

	IntegerDoubleLinkedList::Node * pDyingNode = _pPrevNode->m_pNext;
	_pPrevNode->m_pNext = pDyingNode->m_pNext;

	if (_list.m_pLast == pDyingNode)
		_list.m_pLast = _pPrevNode;

	delete pDyingNode;
}


void IntegerDoubleLinkedListDeleteBefore(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pNextNode)
{
	assert(!IntegerDoubleLinkedListIsEmpty(_list));

	assert(_list.m_pFirst != _pNextNode);

	IntegerDoubleLinkedList::Node * pPrevNode = _list.m_pFirst, *pCurrentNode = _list.m_pFirst->m_pNext;
	if (pCurrentNode == _pNextNode)
	{
		delete _list.m_pFirst;
		_list.m_pFirst = _pNextNode;
	}

	else
	{
		while (pCurrentNode->m_pNext != _pNextNode)
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->m_pNext;
		}

		pPrevNode->m_pNext = _pNextNode;
		delete pCurrentNode;
	}
}


void IntegerDoubleLinkedListDeleteNode(IntegerDoubleLinkedList & _list, IntegerDoubleLinkedList::Node * _pNode)
{
	if (_list.m_pFirst == _pNode)
		IntegerDoubleLinkedListPopFront(_list);

	else if (_list.m_pLast == _pNode)
		IntegerDoubleLinkedListPopBack(_list);

	else
		IntegerDoubleLinkedListDeleteBefore(_list, _pNode->m_pNext);
}


void IntegerDoubleLinkedListPrint(const IntegerDoubleLinkedList & _list, std::ostream & _stream, char _sep)
{
	const IntegerDoubleLinkedList::Node * pCurrent = _list.m_pFirst;
	while (pCurrent)
	{
		_stream << pCurrent->m_value << _sep;
		pCurrent = pCurrent->m_pNext;
	}
}

void IntegerDoubleLinkedListRead(IntegerDoubleLinkedList & _list, std::istream & _stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream)
			IntegerDoubleLinkedListPushBack(_list, temp);
		else
			break;
	}
}

void IntegerDoubleLinkedListReadTillZero(IntegerDoubleLinkedList & _list, std::istream & _stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp != 0)
			IntegerDoubleLinkedListPushBack(_list, temp);
		else
			break;
	}
}

void IntegerDoubleLinkedListPrint(IntegerDoubleLinkedList const & _list, std::ostream & _stream, int _mode)
{
	IntegerDoubleLinkedList::Node * node;
	
	if (_mode == 0) {
		node = _list.m_pFirst;

		while (node)
		{
			_stream << node->m_value << std::ends;
			node = node->m_pNext;
		}
		_stream << std::endl;
	}
	else if (_mode == 1)
	{
		node = _list.m_pLast;
		//пока существуют предыдущие узлы (previous) выводим информацию и двигаемся назад
		while (node)
		{
			_stream << node->m_value << std::ends;
			node = node->previous;
		}
		_stream << std::endl;
	}
}

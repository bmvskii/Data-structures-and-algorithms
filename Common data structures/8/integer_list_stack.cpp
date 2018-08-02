#include "integer_list_stack.hpp"
#include "integer_list.hpp"

#include <cassert>

struct IntegerListStack
{
	IntegerList * m_pData;
	IntegerList * m_pTop;
	int m_nUsed;
	int m_Size;
};


IntegerListStack * IntegerListStackCreate(int _fixedSize)
{
	IntegerListStack * pStack = new IntegerListStack;

	pStack->m_pData = new IntegerList[_fixedSize];
	pStack->m_pTop = pStack->m_pData;
	pStack->m_nUsed = 0;
	pStack->m_Size = _fixedSize;

	return pStack;
}

void IntegerListStackDestroy(IntegerListStack * _pStack)
{
	//пока есть элементы , очищаем списки
	while (_pStack->m_nUsed )
		IntegerListDestroy(_pStack->m_pData[_pStack->m_nUsed--]);

	delete[] _pStack->m_pData;
	delete _pStack;
}

void IntegerListStackPush(IntegerListStack & _stack, IntegerList _value)
{
	//запоминаем первый узел у нашего входящего списка
	IntegerList::Node * pNode = _value.m_pFirst;

	//создаем список
	IntegerList l;
	IntegerListInit(l);

	//пока есть узлы в входящем списке - копируем значения
	while(pNode){
		IntegerListPushBack(l, pNode->m_value);
		pNode = pNode->m_pNext;
	}

	*_stack.m_pTop = l;
	_stack.m_pTop++;
	_stack.m_nUsed++;
}

void IntegerListStackPop(IntegerListStack & _stack)
{
	_stack.m_pTop--;
	_stack.m_nUsed--;
}

IntegerList IntegerListStackTop(const IntegerListStack & _stack)
{
	return *(_stack.m_pTop - 1);
}

bool IntegerListStackIsEmpty(const IntegerListStack & _stack)
{
	return _stack.m_nUsed == 0;
}

bool IntegerListStackIsFull(const IntegerListStack & _stack)
{
	return _stack.m_nUsed == _stack.m_Size;
}

void IntegerListStackClear(IntegerListStack & _stack)
{
	//пока есть списки - освобождаем их
	while (_stack.m_nUsed > 1)
		IntegerListClear(_stack.m_pData[_stack.m_nUsed--]);
	_stack.m_nUsed = 0;
}
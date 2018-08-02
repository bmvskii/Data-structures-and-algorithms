#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cassert>

#include "string_stack.hpp"

struct StringStack
{
	char ** m_pData;
	int m_nUsed;
	int m_Size;
};


StringStack * StringStackCreate(int _fixedSize)
{
	StringStack * pStack = new StringStack;

	pStack->m_pData = new char*[_fixedSize];
	pStack->m_nUsed = 0;
	pStack->m_Size = _fixedSize;

	return pStack;
}


void StringStackDestroy(StringStack * _pStack)
{
	delete[] _pStack->m_pData;
	delete _pStack;
}


void StringStackClear(StringStack & _stack)
{
	for (int i = 0; i < _stack.m_nUsed; i++)
		delete _stack.m_pData[i];
}


void StringStackPush(StringStack & _stack, const char * _value)
{
	assert(!StringStackIsFull(_stack));
	_stack.m_pData[_stack.m_nUsed] = new char[strlen(_value)+1];
	strcpy(_stack.m_pData[_stack.m_nUsed++], _value);
}


void StringStackPop(StringStack & _stack)
{
	assert(!StringStackIsEmpty(_stack));
	delete[]_stack.m_pData[_stack.m_nUsed - 1];
	_stack.m_nUsed--;
}


const char * StringStackTop(const StringStack & _stack)
{
	assert(!StringStackIsEmpty(_stack));
	return _stack.m_pData[_stack.m_nUsed-1];
}


bool StringStackIsEmpty(const StringStack & _stack)
{
	return _stack.m_nUsed == 0;
}


bool StringStackIsFull(const StringStack & _stack)
{
	return _stack.m_nUsed == _stack.m_Size;
}
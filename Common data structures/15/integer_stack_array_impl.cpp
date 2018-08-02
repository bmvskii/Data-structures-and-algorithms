#include "integer_stack.hpp"
#include <cassert>

struct IntegerDroppingStack
{
    int * m_pData;
    int * m_pTop;
    int m_Size;
};


IntegerDroppingStack * IntegerDroppingStackCreate ( int _fixedSize )
{
    IntegerDroppingStack * pStack = new IntegerDroppingStack;
    
    pStack->m_pData = new int[ _fixedSize ];
    pStack->m_pTop  = pStack->m_pData;
    pStack->m_Size  = _fixedSize;

    return pStack;
}


void IntegerDroppingStackDestroy ( IntegerDroppingStack * _pStack )
{
    delete[] _pStack->m_pData;
    delete _pStack;
}


void IntegerDroppingStackClear ( IntegerDroppingStack & _stack )
{
    _stack.m_pTop  = _stack.m_pData;
}


void IntegerDroppingStackPush ( IntegerDroppingStack & _stack, int _value )
{
	//вычисляем текущий размер стека
	int currentSize = _stack.m_pTop - _stack.m_pData;
	//если стек заполнен, то
	//удаляем самый старый и присваиваем значение "верхушке"
	if (IntegerDroppingStackIsFull(_stack))
	{
		for (int i = 1; i < currentSize; i++)
			_stack.m_pData[i - 1] = _stack.m_pData[i];
		_stack.m_pData[currentSize-1] = _value;
	}
	//в противном случае, двигаемся вперед и увеличиваем размер
	else {
		*_stack.m_pTop = _value;
		++_stack.m_pTop;
	}
}


void IntegerDroppingStackPop ( IntegerDroppingStack & _stack )
{
    assert( ! IntegerDroppingStackIsEmpty( _stack ) );
    -- _stack.m_pTop;
}


int IntegerDroppingStackTop ( const IntegerDroppingStack & _stack )
{
    assert( ! IntegerDroppingStackIsEmpty( _stack ) );
    return * ( _stack.m_pTop - 1 );
}


bool IntegerDroppingStackIsEmpty ( const IntegerDroppingStack & _stack )
{
    return _stack.m_pData == _stack.m_pTop;
}


bool IntegerDroppingStackIsFull ( const IntegerDroppingStack & _stack )
{
    return ( _stack.m_pTop - _stack.m_pData ) == _stack.m_Size;
}
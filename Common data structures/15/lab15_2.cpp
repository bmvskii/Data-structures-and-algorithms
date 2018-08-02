#include <iostream>
#include <cassert>

#include "integer_stack.hpp"

int main()
{
	// ������� ���� ��� �������� 5 ���������
	IntegerDroppingStack * pStack = IntegerDroppingStackCreate(5);

	// ��������� ���� ������� �� �������
	IntegerDroppingStackPush(*pStack, 1);
	IntegerDroppingStackPush(*pStack, 2);
	IntegerDroppingStackPush(*pStack, 3);
	IntegerDroppingStackPush(*pStack, 4);
	IntegerDroppingStackPush(*pStack, 5);

	// ���������� � ������� ����� � �������� �� �������
	assert(IntegerDroppingStackIsFull(*pStack));
	assert(IntegerDroppingStackTop(*pStack) == 5);

	// ��������� ����� ������ ������ ������
	IntegerDroppingStackPush(*pStack, 6);

	// ���������� � ������� ����� � ��������� ����� �������
	assert(IntegerDroppingStackIsFull(*pStack));
	assert(IntegerDroppingStackTop(*pStack) == 6);

	// ���������� ����
	IntegerDroppingStackDestroy(pStack);

	return 0;
}
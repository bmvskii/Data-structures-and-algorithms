#include <iostream>
#include <cassert>
#include "integer_list_stack.hpp"
#include "integer_list.hpp"

int main()
{
	// ������� ����
	IntegerListStack * stack = IntegerListStackCreate(10);
	// ������� ���� ������ ������� � ��������� �� �������
	IntegerList list1, list2, list3;
	IntegerListInit(list1);
	IntegerListInit(list2);
	IntegerListInit(list3);
	//��������� ��������� �������� � 3 ������
	for (int i = 0; i < 3; i++) IntegerListPushBack(list1, i);
	for (int i = 0; i < 7; i+=2) IntegerListPushBack(list2, i);
	for (int i = 3; i < 16; i+=3) IntegerListPushBack(list3, i);
	// ��������� ������ � ����
	IntegerListStackPush(*stack, list1);
	IntegerListStackPush(*stack, list2);
	IntegerListStackPush(*stack, list3);
	// ������� ������, ��� �� ������ �������� �� ������ � �����
	IntegerListClear(list1);
	IntegerListClear(list2);
	// ��������� ������ �� ������� ����� � ������� ������
	const IntegerList & listTop = IntegerListStackTop(*stack);
	assert(IntegerListStackTop(*stack).m_pLast->m_value == 15);
	// ������� ������� � ������� �����
	IntegerListStackPop(*stack);
	// ��������� ������ �� ������� ����� � ������� ������
	assert(IntegerListStackTop(*stack).m_pLast->m_value == 6);
	IntegerListStackPop(*stack);
	// ��������� ������ �� ������� ����� � ������� ������
	assert(IntegerListStackTop(*stack).m_pLast->m_value == 2);
	//������� ��� ����
	IntegerListStackClear(*stack);
	//��������� , ��� ��� ���� ������
	assert(IntegerListStackIsEmpty(*stack));
	// ���������� ����
	IntegerListStackDestroy(stack);
	return 0;
}
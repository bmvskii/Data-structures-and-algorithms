#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cassert>

#include "string_stack.hpp"

int main()
{
	// ������� ���� �� 10 �����
	StringStack * pStack = StringStackCreate(10);

	// ��������� � ���� ������� ������-�������
	StringStackPush(*pStack, "Hello");

	// ��������� � ���� ������� ������ �� ���������� ������
	char temp[100];
	std::cin >> temp; // ������ ����� Goodbye � �������
	StringStackPush(*pStack, temp);

	// ������� �����, ������ � ������� �� ������ ���� ������
	temp[0] = '\0';

	// �������� ����� � ������������ ������ � ��������� ������ � ������
	char * pDynamicBuf = new char[100];
	std::cin >> pDynamicBuf; // ������ ����� Thanks � �������
	StringStackPush(*pStack, pDynamicBuf);

	// ����������� ������, ������ � ������� �� ������ ���� ������
	delete[] pDynamicBuf;

	// ��������� �������� ����� � �����
	assert(!strcmp(StringStackTop(*pStack), "Thanks"));
	StringStackPop(*pStack);
	assert(!strcmp(StringStackTop(*pStack), "Goodbye"));
	StringStackPop(*pStack);
	assert(!strcmp(StringStackTop(*pStack), "Hello"));
	StringStackPop(*pStack);

	// ���������� ���� ������ �� ����� ��������
	StringStackDestroy(pStack);
	return 0;
}
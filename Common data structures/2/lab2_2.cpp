#define _CRT_SECURE_NO_WARNINGS

#include "string_list.hpp"

#include <iostream>
#include <cassert>

int main()
{
	// ������� � �������������� ������
	StringList l;
	StringListInit(l);

	// ��������� � ������ ������� ������-�������
	StringListPushBack(l, "Hello");

	// ��������� � ������ ������� ������ �� ���������� ������
	char temp[100];
	std::cin >> temp; // ������ ����� Goodbye � �������
	StringListPushBack(l, temp);

	// ������� �����, ������ � ������ �� ������ ���� ������
	temp[0] = '\0';

	// �������� ����� � ������������ ������ � ��������� ������ � ������
	char * pDynamicBuf = new char[100];
	std::cin >> pDynamicBuf; // ������ ����� Thanks � �������
	StringListPushBack(l, pDynamicBuf);

	// ����������� ������, ������ � ������ �� ������ ���� ������
	delete[] pDynamicBuf;

	// ��������� �������� ����� � ������
	assert(!strcmp(l.m_pFirst->m_value, "Hello"));
	assert(!strcmp(l.m_pFirst->m_pNext->m_value, "Goodbye"));
	assert(!strcmp(l.m_pLast->m_value, "Thanks"));

	// ���������� ������ ������ �� ����� ��������
	StringListDestroy(l);

	return 0;
}
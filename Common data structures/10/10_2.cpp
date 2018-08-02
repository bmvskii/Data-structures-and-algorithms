#include <iostream>
#include <cassert>

#include "integer_list.hpp"\

int main()
{
	//��������� ����� � ���������������
	{
		//������� � �������������� ������
		IntegerList * pList = new IntegerList();
		IntegerListInit(*pList);

		//��������� �������� �� 0 �� 4 ������������
		for (int i = 0; i < 5; i++) IntegerListPushBack(*pList, i);

		//���������, ��� ����� : 0 + 1 + 2 + 3 + 4 = 10
		assert(IntegerListAccumulate(*pList) == 10);

		//�.�. ��������� ���������������, �� ������ ������ ���� ����������
		assert(IntegerListIsSorted(*pList));
		IntegerListDestroy(*pList);
	}
	
	//��������� �����������������
	{
		IntegerList * pList = new IntegerList();
		IntegerListInit(*pList);

		IntegerListPushBack(*pList, 1);
		IntegerListPushBack(*pList, 2);
		IntegerListPushBack(*pList, 0);

		assert(!IntegerListIsSorted(*pList));
		IntegerListDestroy(*pList);
	}
	//��������� ����������
	{
		//������� ������ � �������������� ���
		IntegerList * pList = new IntegerList();
		IntegerListInit(*pList);

		for (int i = 0; i < 10; i++) IntegerListPushBack(*pList, i + 1);

		//������� 2 ������ � �������������� ��
		IntegerList * pFirstHalf = new IntegerList();
		IntegerListInit(*pFirstHalf);

		IntegerList * pSecondHalf = new IntegerList();
		IntegerListInit(*pSecondHalf);

		//�������� ������ ����, ������ �� ������ ���� ���������
		IntegerListSplice(*pList, nullptr, *pFirstHalf, *pSecondHalf);

		assert(IntegerListIsEmpty(*pFirstHalf));
		assert(IntegerListIsEmpty(*pSecondHalf));

		//������� ����������� ����
		IntegerList::Node * divNode = new IntegerList::Node;
		divNode->m_value = 7;
		divNode->m_pNext = nullptr;

		//��������� ������
		IntegerListSplice(*pList, divNode, *pFirstHalf, *pSecondHalf);

		//��������� �������� � ����� �������
		assert(pFirstHalf->m_pLast->m_value == 6);
		assert(pSecondHalf->m_pLast->m_value == 10);
		assert(pFirstHalf->m_pFirst->m_value == 1);
		assert(pSecondHalf->m_pFirst->m_value == 7);

		//������� ���
		delete divNode;
		IntegerListDestroy(*pFirstHalf);
		IntegerListDestroy(*pSecondHalf);
		IntegerListDestroy(*pList);
	}

	return 0;
}
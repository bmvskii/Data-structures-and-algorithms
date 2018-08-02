#include <iostream>
#include <cassert>

#include "integer_list.hpp"\

int main()
{
	//тестируем сумму и упорядоченность
	{
		//создаем и инициализируем список
		IntegerList * pList = new IntegerList();
		IntegerListInit(*pList);

		//добавляем элементы от 0 до 4 включительно
		for (int i = 0; i < 5; i++) IntegerListPushBack(*pList, i);

		//проверяем, что сумма : 0 + 1 + 2 + 3 + 4 = 10
		assert(IntegerListAccumulate(*pList) == 10);

		//т.к. вставляли последовательно, то список должен быть упорядочен
		assert(IntegerListIsSorted(*pList));
		IntegerListDestroy(*pList);
	}
	
	//тестируем неупорядоченность
	{
		IntegerList * pList = new IntegerList();
		IntegerListInit(*pList);

		IntegerListPushBack(*pList, 1);
		IntegerListPushBack(*pList, 2);
		IntegerListPushBack(*pList, 0);

		assert(!IntegerListIsSorted(*pList));
		IntegerListDestroy(*pList);
	}
	//тестируем разделение
	{
		//создаем список и инициализируем его
		IntegerList * pList = new IntegerList();
		IntegerListInit(*pList);

		for (int i = 0; i < 10; i++) IntegerListPushBack(*pList, i + 1);

		//создаем 2 списка и инициализируем их
		IntegerList * pFirstHalf = new IntegerList();
		IntegerListInit(*pFirstHalf);

		IntegerList * pSecondHalf = new IntegerList();
		IntegerListInit(*pSecondHalf);

		//передаем пустой узел, ничего не должно быть добавлено
		IntegerListSplice(*pList, nullptr, *pFirstHalf, *pSecondHalf);

		assert(IntegerListIsEmpty(*pFirstHalf));
		assert(IntegerListIsEmpty(*pSecondHalf));

		//создаем разделяющий узел
		IntegerList::Node * divNode = new IntegerList::Node;
		divNode->m_value = 7;
		divNode->m_pNext = nullptr;

		//разделяем список
		IntegerListSplice(*pList, divNode, *pFirstHalf, *pSecondHalf);

		//проверяем значения в новых списках
		assert(pFirstHalf->m_pLast->m_value == 6);
		assert(pSecondHalf->m_pLast->m_value == 10);
		assert(pFirstHalf->m_pFirst->m_value == 1);
		assert(pSecondHalf->m_pFirst->m_value == 7);

		//удаляем все
		delete divNode;
		IntegerListDestroy(*pFirstHalf);
		IntegerListDestroy(*pSecondHalf);
		IntegerListDestroy(*pList);
	}

	return 0;
}
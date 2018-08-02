#include <iostream>
#include <cassert>
#include "integer_list_stack.hpp"
#include "integer_list.hpp"

int main()
{
	// создаем стек
	IntegerListStack * stack = IntegerListStackCreate(10);
	// создаем пару разных списков и заполняем их данными
	IntegerList list1, list2, list3;
	IntegerListInit(list1);
	IntegerListInit(list2);
	IntegerListInit(list3);
	//добавляем различные значения в 3 списка
	for (int i = 0; i < 3; i++) IntegerListPushBack(list1, i);
	for (int i = 0; i < 7; i+=2) IntegerListPushBack(list2, i);
	for (int i = 3; i < 16; i+=3) IntegerListPushBack(list3, i);
	// добавляем списки в стек
	IntegerListStackPush(*stack, list1);
	IntegerListStackPush(*stack, list2);
	IntegerListStackPush(*stack, list3);
	// очищаем списки, это не должно повлиять на списки в стеке
	IntegerListClear(list1);
	IntegerListClear(list2);
	// извлекаем список из вершины стека и сверяем данные
	const IntegerList & listTop = IntegerListStackTop(*stack);
	assert(IntegerListStackTop(*stack).m_pLast->m_value == 15);
	// убираем элемент с вершины стека
	IntegerListStackPop(*stack);
	// извлекаем список из вершины стека и сверяем данные
	assert(IntegerListStackTop(*stack).m_pLast->m_value == 6);
	IntegerListStackPop(*stack);
	// извлекаем список из вершины стека и сверяем данные
	assert(IntegerListStackTop(*stack).m_pLast->m_value == 2);
	//очищаем наш стек
	IntegerListStackClear(*stack);
	//проверяем , что наш стек пустой
	assert(IntegerListStackIsEmpty(*stack));
	// уничтожаем стек
	IntegerListStackDestroy(stack);
	return 0;
}
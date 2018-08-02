#define _CRT_SECURE_NO_WARNINGS

#include "string_list.hpp"

#include <iostream>
#include <cassert>

int main()
{
	// создаем и инициализируем список
	StringList l;
	StringListInit(l);

	// добавляем в список обычную строку-литерал
	StringListPushBack(l, "Hello");

	// добавляем в список обычную строку из временного буфера
	char temp[100];
	std::cin >> temp; // вводим текст Goodbye с консоли
	StringListPushBack(l, temp);

	// очищаем буфер, строка в списке не должна быть задета
	temp[0] = '\0';

	// выделяем буфер в динамической памяти и добавляем строку в список
	char * pDynamicBuf = new char[100];
	std::cin >> pDynamicBuf; // вводим текст Thanks с консоли
	StringListPushBack(l, pDynamicBuf);

	// освобождаем память, строка в списке не должна быть задета
	delete[] pDynamicBuf;

	// проверяем значения строк в списке
	assert(!strcmp(l.m_pFirst->m_value, "Hello"));
	assert(!strcmp(l.m_pFirst->m_pNext->m_value, "Goodbye"));
	assert(!strcmp(l.m_pLast->m_value, "Thanks"));

	// уничтожаем список вместе со всеми строками
	StringListDestroy(l);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cassert>

#include "string_stack.hpp"

int main()
{
	// создаем стек из 10 строк
	StringStack * pStack = StringStackCreate(10);

	// добавляем в стек обычную строку-литерал
	StringStackPush(*pStack, "Hello");

	// добавляем в стек обычную строку из временного буфера
	char temp[100];
	std::cin >> temp; // вводим текст Goodbye с консоли
	StringStackPush(*pStack, temp);

	// очищаем буфер, строка в векторе не должна быть задета
	temp[0] = '\0';

	// выделяем буфер в динамической памяти и добавляем строку в вектор
	char * pDynamicBuf = new char[100];
	std::cin >> pDynamicBuf; // вводим текст Thanks с консоли
	StringStackPush(*pStack, pDynamicBuf);

	// освобождаем память, строка в векторе не должна быть задета
	delete[] pDynamicBuf;

	// проверяем значения строк в стеке
	assert(!strcmp(StringStackTop(*pStack), "Thanks"));
	StringStackPop(*pStack);
	assert(!strcmp(StringStackTop(*pStack), "Goodbye"));
	StringStackPop(*pStack);
	assert(!strcmp(StringStackTop(*pStack), "Hello"));
	StringStackPop(*pStack);

	// уничтожаем стек вместе со всеми строками
	StringStackDestroy(pStack);
	return 0;
}
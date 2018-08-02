#include <iostream>
#include <cassert>

#include "integer_stack.hpp"

int main()
{
	// создаем стек для хранения 5 элементов
	IntegerDroppingStack * pStack = IntegerDroppingStackCreate(5);

	// заполняем стек данными до предела
	IntegerDroppingStackPush(*pStack, 1);
	IntegerDroppingStackPush(*pStack, 2);
	IntegerDroppingStackPush(*pStack, 3);
	IntegerDroppingStackPush(*pStack, 4);
	IntegerDroppingStackPush(*pStack, 5);

	// убеждаемся в полноте стека и элементе на вершине
	assert(IntegerDroppingStackIsFull(*pStack));
	assert(IntegerDroppingStackTop(*pStack) == 5);

	// добавляем новое данное “сверх нормы”
	IntegerDroppingStackPush(*pStack, 6);

	// убеждаемся в полноте стека и появлению новой вершины
	assert(IntegerDroppingStackIsFull(*pStack));
	assert(IntegerDroppingStackTop(*pStack) == 6);

	// Уничтожаем стек
	IntegerDroppingStackDestroy(pStack);

	return 0;
}
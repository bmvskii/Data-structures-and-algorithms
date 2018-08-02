#include <iostream>
#include "integer_list.hpp"

int main()
{
	//создаем указатель на целочисленный список
	IntegerList * pIntegerList = new IntegerList();

	//инициализируем
	IntegerListInit(*pIntegerList);

	//считываем входную последовательность чисел
	IntegerListReadTillZero(*pIntegerList, std::cin);

	//запускаем требуемый от задачи процесс
	IntegerListDeleteIfLower(*pIntegerList);

	//уничтожаем список
	IntegerListDestroy(*pIntegerList);

	return 0;
}
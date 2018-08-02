#include <iostream>
#include <cassert>

#include "integer_set.hpp"

int main()
{
	//создаем и иницилалируем 3 множества
	IntegerSet * pSet = IntegerSetCreate();
	IntegerSet * pEqualSet = IntegerSetCreate();
	IntegerSet * pSubset = IntegerSetCreate();

	//заполняем 2 множества от 1 до 10
	for (int i = 0; i < 10; i++) {
		IntegerSetInsertKey(*pSet, i + 1);
		IntegerSetInsertKey(*pEqualSet, i + 1);
	}
		
	//заполняем 1 множество от 3 до 7
	for (int i = 2; i < 7; i++) IntegerSetInsertKey(*pSubset, i + 1);

	//первое и второе должны быть равны
	assert(IntegerSetIsEqual(*pSet, *pEqualSet));
	
	//третье должно быть подможножеством и первого, и второго
	assert(IntegerSetIsSubset(*pSet, *pSubset));
	assert(IntegerSetIsSubset(*pEqualSet, *pSubset));

	//максимальный элемент
	assert(IntegerSetMaxKey(*pSet) == 10);
	assert(IntegerSetMaxKey(*pSubset) == 7);

	//минимальный элемент
	assert(IntegerSetMinKey(*pSet) == 1);
	assert(IntegerSetMinKey(*pSubset) == 3);

	//уничтожаем множества
	IntegerSetDestroy(pEqualSet);
	IntegerSetDestroy(pSubset);
	IntegerSetDestroy(pSet);
	return 0;
}
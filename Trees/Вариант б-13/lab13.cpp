#include <iostream>
#include <cassert>

#include "bstree.hpp"
#include "integer_vector.hpp"

int main()
{
	//создаем дерево
	BSTree * pBST = BSTreeCreate();
	
	//создаем и инициализируем 3 вектора
	IntegerVector vector1;	IntegerVectorInit(vector1);
	IntegerVector vector2;  IntegerVectorInit(vector2);
	IntegerVector vector3;	IntegerVectorInit(vector3);

	//вставляем элементы в вектора
	IntegerVectorPushBack(vector1, 5);
	IntegerVectorPushBack(vector1, 4);
	IntegerVectorPushBack(vector1, 3);

	IntegerVectorPushBack(vector2, 1);
	IntegerVectorPushBack(vector2, 2);
	IntegerVectorPushBack(vector2, 3);
	IntegerVectorPushBack(vector2, 4);
	IntegerVectorPushBack(vector2, 5);

	IntegerVectorPushBack(vector3, 2);
	IntegerVectorPushBack(vector3, 3);
	IntegerVectorPushBack(vector3, 4);
	IntegerVectorPushBack(vector3, 5);

	//вставляем вектор в дерево
	BSTreeInsertKey(*pBST, vector1);
	BSTreeInsertKey(*pBST, vector2);
	BSTreeInsertKey(*pBST, vector3);

	//проверяем что в максимуме у нас вектор номер 1 , а в минимуме 2
	assert(!IntegerVectorComparation(BSTreeMaximum(*pBST), vector1));
	assert(!IntegerVectorComparation(BSTreeMinimum(*pBST), vector2));

	//удаляем первый вектор и смотрим , что в максимуме теперь 3 вектор
	BSTreeDeleteKey(*pBST, vector1);
	assert(!IntegerVectorComparation(BSTreeMaximum(*pBST), vector3));

	//удалить 3 вектор
	IntegerVectorDestroy(vector1);
	IntegerVectorDestroy(vector2);
	IntegerVectorDestroy(vector3);

	//удалить дерево
	BSTreeDestroy(pBST);
	return 0;
}
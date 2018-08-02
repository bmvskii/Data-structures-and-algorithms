#include <iostream>
#include <cassert>
#include "integer_vector_queue.hpp"
#include "integer_vector.hpp"
#include "vld.h"

int main()
{
	// создаем очередь
	IntegerVectorQueue * pQ = IntegerVectorQueueCreate();

	// создаем пару разных векторов и заполняем их данными
	IntegerVector v1, v2;
	IntegerVectorInit(v1);
	IntegerVectorInit(v2);

	IntegerVectorPushBack(v1, 1);
	IntegerVectorPushBack(v1, 2);
	IntegerVectorPushBack(v1, 3);

	IntegerVectorPushBack(v2, 0);
	IntegerVectorPushBack(v2, 2);
	IntegerVectorPushBack(v2, 4);
	IntegerVectorPushBack(v2, 6);

	// добавляем вектора в очередь
	IntegerVectorQueuePush(*pQ, v1);
	IntegerVectorQueuePush(*pQ, v2);

	// очищаем вектора, это не должно повлиять на вектора в очереди
	IntegerVectorDestroy(v1);
	IntegerVectorDestroy(v2);

	// извлекаем вектор из начала очереди и сверяем данные
	const IntegerVector & vFront = IntegerVectorQueueFront(*pQ);
	assert(vFront.m_nUsed == 3 && vFront.m_pData[1] == 2);

	// убираем элемент в начале очереди
	IntegerVectorQueuePop(*pQ);

	// извлекаем вектор из начала очереди и сверяем данные
	const IntegerVector & vFront2 = IntegerVectorQueueFront(*pQ);
	assert(vFront2.m_nUsed == 4 && vFront2.m_pData[3] == 6);

	// уничтожаем очередь
	IntegerVectorQueueDestroy(pQ);
	return 0;
}
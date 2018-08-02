#include <iostream>
#include <cassert>
#include "integer_vector_queue.hpp"
#include "integer_vector.hpp"
#include "vld.h"

int main()
{
	// ������� �������
	IntegerVectorQueue * pQ = IntegerVectorQueueCreate();

	// ������� ���� ������ �������� � ��������� �� �������
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

	// ��������� ������� � �������
	IntegerVectorQueuePush(*pQ, v1);
	IntegerVectorQueuePush(*pQ, v2);

	// ������� �������, ��� �� ������ �������� �� ������� � �������
	IntegerVectorDestroy(v1);
	IntegerVectorDestroy(v2);

	// ��������� ������ �� ������ ������� � ������� ������
	const IntegerVector & vFront = IntegerVectorQueueFront(*pQ);
	assert(vFront.m_nUsed == 3 && vFront.m_pData[1] == 2);

	// ������� ������� � ������ �������
	IntegerVectorQueuePop(*pQ);

	// ��������� ������ �� ������ ������� � ������� ������
	const IntegerVector & vFront2 = IntegerVectorQueueFront(*pQ);
	assert(vFront2.m_nUsed == 4 && vFront2.m_pData[3] == 6);

	// ���������� �������
	IntegerVectorQueueDestroy(pQ);
	return 0;
}
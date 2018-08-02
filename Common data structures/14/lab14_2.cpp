#include <cassert>
#include "integer_queue.hpp"

int main() {

	// ������� ������� ��� �������� 5 ���������
	IntegerDroppingQueue * pQ = IntegerDroppingQueueCreate(5);

	// ��������� ������� ������� �� �������
	IntegerDroppingQueuePush(*pQ, 1);
	IntegerDroppingQueuePush(*pQ, 2);
	IntegerDroppingQueuePush(*pQ, 3);
	IntegerDroppingQueuePush(*pQ, 4);
	IntegerDroppingQueuePush(*pQ, 5);

	// ���������� � ������� ������� � ��������� ��������
	assert(IntegerDroppingQueueIsFull(*pQ));
	assert(IntegerDroppingQueueFront(*pQ) == 1);

	// ��������� ����� ������ ������ ������
	IntegerDroppingQueuePush(*pQ, 6);

	// ������ ����� ������ ���� ���� ���������, �� ������� ��� ���� �����
	assert(IntegerDroppingQueueIsFull(*pQ));
	assert(IntegerDroppingQueueFront(*pQ) == 2);

	// ���������� �������
	IntegerDroppingQueueDestroy(pQ);
	return 0;
}
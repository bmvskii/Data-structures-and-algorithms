#include <iostream>
#include <cassert>

#include "point3d_queue.hpp"
#include "point3d_list.hpp"

int main()
{
	// ������� �������
	Point3DQueue* pQ = Point3DQueueCreate();

	// �������� � ������� 3 �����
	Point3D p1 = { 0.0, 0.0, 0.0 };
	Point3D p2 = { 1.0, 1.0, 1.0 };
	Point3D p3 = { -1.0, -1.0, -1.0 };

	Point3DQueuePush(*pQ, p1);
	Point3DQueuePush(*pQ, p2);
	Point3DQueuePush(*pQ, p2);

	// ������� ������ ����� �� �������
	Point3DQueuePop(*pQ);

	// ��������� ����� � ������ �������, ���������, ��� ��� ����� p2
	Point3D p = Point3DQueueFront(*pQ);
	assert(p.x == p2.x && p.y == p2.y && p.z == p2.z);

	Point3DQueuePop(*pQ);

	// ��������� ����� � ������ �������, ���������, ��� ��� ����� p3
	p = Point3DQueueFront(*pQ);
	assert(p.x == p3.x && p.y == p3.y && p.z == p3.z);

	Point3DQueueClear(*pQ);
	assert(Point3DQueueIsEmpty(*pQ));

	// ���������� �������
	Point3DQueueDestroy(pQ);

	return 0;
}
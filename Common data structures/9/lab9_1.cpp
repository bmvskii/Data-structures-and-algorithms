#include <iostream>
#include "integer_list.hpp"

int main()
{
	//������� ��������� �� ������������� ������
	IntegerList * pIntegerList = new IntegerList();

	//��������������
	IntegerListInit(*pIntegerList);

	//��������� ������� ������������������ �����
	IntegerListReadTillZero(*pIntegerList, std::cin);

	//��������� ��������� �� ������ �������
	IntegerListDeleteIfLower(*pIntegerList);

	//���������� ������
	IntegerListDestroy(*pIntegerList);

	return 0;
}
#include <iostream>
#include "integer_vector.hpp"

int main()
{
	//������� � ������������� ������
	IntegerVector * v = new IntegerVector();
	IntegerVectorInit(*v);
	
	//��������� �� CRTL+Z
	IntegerVectorRead(*v, std::cin);
	//������� ��� ����� 5 ���������
	IntegerVectorCustomerPrint(*v, std::cout);

	//���������� ������
	IntegerVectorDestroy(*v);
	return 0;
}
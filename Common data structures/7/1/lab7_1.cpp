#include <iostream>

#include "integer_vector.hpp"

int main()
{
	//������� � �������������� ������
	IntegerVector * pVector = new IntegerVector();
	IntegerVectorInit(*pVector);

	//�������� ���� �������
	IntegerVectorCustomRead(*pVector,std::cin);
	
	//������� ������
	IntegerVectorDestroy(*pVector);
	return 0;
}
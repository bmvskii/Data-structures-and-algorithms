#include <iostream>
#include "integer_vector.hpp"

int main()
{
	IntegerVector * pVector = new IntegerVector;
	IntegerVectorInit(*pVector);

	IntegerVectorReadTillZero(*pVector,std::cin);

	IntegerVector v = *pVector;
	int p;

	std::cin >> p;
	//����� � �������� �������� �������� , ������� ����� �������
	for (int i = v.m_nUsed - 1; i >= p - 1; i--) std::cout << v.m_pData[i] << " ";

	//����� ��������� � ������ �������, ������� �� �������
	for (int i = 0; i < p - 1; i++) std::cout << v.m_pData[i] << " ";
	std::cout << std::endl;

	IntegerVectorDestroy(*pVector);
	return 0;
}
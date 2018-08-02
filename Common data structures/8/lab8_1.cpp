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
	//вывод в обратном поряждке элементв , стоящих после позиции
	for (int i = v.m_nUsed - 1; i >= p - 1; i--) std::cout << v.m_pData[i] << " ";

	//вывод элементов в прямом порядке, стоящих до позиции
	for (int i = 0; i < p - 1; i++) std::cout << v.m_pData[i] << " ";
	std::cout << std::endl;

	IntegerVectorDestroy(*pVector);
	return 0;
}
#include <iostream>

#include "integer_vector.hpp"

int main()
{
	//создаем и инициализируем вектор
	IntegerVector * pVector = new IntegerVector();
	IntegerVectorInit(*pVector);

	//вызываем нашу функцию
	IntegerVectorCustomRead(*pVector,std::cin);
	
	//удаляем вектор
	IntegerVectorDestroy(*pVector);
	return 0;
}
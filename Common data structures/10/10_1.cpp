#include <iostream>
#include "integer_vector.hpp"

int main()
{
	//создаем и иницализируем вектор
	IntegerVector * v = new IntegerVector();
	IntegerVectorInit(*v);
	
	//считываем до CRTL+Z
	IntegerVectorRead(*v, std::cin);
	//выводим все после 5 введенных
	IntegerVectorCustomerPrint(*v, std::cout);

	//уничтожаем вектор
	IntegerVectorDestroy(*v);
	return 0;
}
#include <iostream>
#include "integer_vector.hpp"

int main()
{
	IntegerVector * pVector = new IntegerVector();
	IntegerVectorInit(*pVector);

	IntegerVectorReadTillZero(*pVector, std::cin);

	IntegerVectorShowElementOnPosition(*pVector, std::cin, std::cout);

	IntegerVectorDestroy(*pVector);
	return 0;
}
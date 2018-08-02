#include <iostream>
#include "integer_vector.hpp"

int main()
{
	IntegerVector * pV = new IntegerVector();
	IntegerVectorInit(*pV);

	IntegerVectorRead(*pV,std::cin);
	IntegerVectorPrint(*pV,std::cout);

	IntegerVectorDestroy(*pV);
	return 0;
}
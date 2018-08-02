#include <iostream>
#include "integer_vector.hpp"

int main()
{
	IntegerVector *vec = new IntegerVector();
	IntegerVectorInit(*vec);

	IntegerVectorReadTillZero(*vec,std::cin);
	IntegerVectorPrintSequences(*vec, std::cout);

	IntegerVectorDestroy(*vec);
	return 0;
}
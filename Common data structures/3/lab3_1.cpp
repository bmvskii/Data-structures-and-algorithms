#include <iostream>
#include "integer_vector.hpp"

int main()
{
	IntegerVector * vector = new IntegerVector();
	IntegerVectorInit(*vector);

	IntegerVectorReadTillZero(*vector,std::cin);

	int pos;
	std::cin >> pos;
	
	if (pos < 0 || pos >= vector->m_nUsed)
	{
		std::cout << "Wrong position. Try again." << std::endl;
		return -1;
	}

	IntegerVectorShow(*vector,pos,std::cout);

	IntegerVectorDestroy(*vector);
	return 0;
}
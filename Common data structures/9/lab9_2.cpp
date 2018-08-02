#include <iostream>
#include <cassert>

#include "integer_vector.hpp"

int main()
{
	IntegerVector *pIntegerVector = new IntegerVector();
	IntegerVectorInit(*pIntegerVector, 10);

	for (int i = 0; i < 10; i++) IntegerVectorPushBack(*pIntegerVector, i+1);
	assert(IntegerVectorAllocated(*pIntegerVector) == 10);
	
	IntegerVectorReserve(*pIntegerVector, 350);
	assert(IntegerVectorAllocated(*pIntegerVector) == 350);

	IntegerVectorShrinkToFit(*pIntegerVector);
	for (int i = 0; i < 3; i++)
		IntegerVectorPopBack(*pIntegerVector);

	assert(IntegerVectorRemainingCapacity(*pIntegerVector) == 7);
	IntegerVectorDestroy(*pIntegerVector);
	
	return 0;
}
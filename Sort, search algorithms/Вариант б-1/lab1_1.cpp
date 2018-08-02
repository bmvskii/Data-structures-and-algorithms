#include <iostream>
#include <cassert>
#include "integer_map.hpp"

int main()
{
	IntegerMap * map = IntegerMapCreate();
	
	IntegerMapInsertKey(*map, 1, 100);
	IntegerMapInsertKey(*map, 2, 200);
	IntegerMapInsertKey(*map, 3, 300);

	assert(IntegerMapGet(*map, 2) == 200);
	assert(IntegerMapGet(*map, 1) == 100);

	assert(IntegerMapHasKey(*map, 2));
	IntegerMapRemoveKey(*map, 2);
	assert(!IntegerMapHasKey(*map, 2));

	IntegerMapDestroy(map);
	return 0;
}
#include <iostream>
#include "integer_map.hpp"

int main()
{
	IntegerMap * pMap = IntegerMapCreate();
	
	IntegerMapInsertKey(*pMap, 1, 100);
	IntegerMapInsertKey(*pMap, 2, 200);
	IntegerMapInsertKey(*pMap, 5, 500);
	IntegerMapInsertKey(*pMap, 4, 400);
	IntegerMapInsertKey(*pMap, 3, 300);

	show(*pMap);

	IntegerMapRemoveKey(*pMap, 2);
	IntegerMapRemoveKey(*pMap, 3);

	show(*pMap);

	IntegerMapDestroy(pMap);
	return 0;
}
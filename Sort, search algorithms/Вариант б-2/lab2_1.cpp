#include <iostream>
#include <cassert>

#include "string_double_map.hpp"

int main()
{
	String2DoubleMap * pMap = String2DoubleMapCreate();

	String2DoubleMapInsertKey(*pMap, "AAAA", 100.0);
	String2DoubleMapInsertKey(*pMap, "BBBB", 200.0);
	String2DoubleMapInsertKey(*pMap, "CCCC", 300.0);

	assert(String2DoubleMapGet(*pMap, "AAAA") == 100.0);
	assert(String2DoubleMapGet(*pMap, "BBBB") == 200.0);
	assert(String2DoubleMapGet(*pMap, "CCCC") == 300.0);

	assert(!String2DoubleMapHasKey(*pMap, "DDDD"));
	
	String2DoubleMapRemoveKey(*pMap, "AAAA");
	assert(!String2DoubleMapHasKey(*pMap, "AAAA"));

	String2DoubleMapRemoveKey(*pMap, "BBBB");
	String2DoubleMapRemoveKey(*pMap, "CCCC");

	assert(String2DoubleMapIsEmpty(*pMap));

	String2DoubleMapDestroy(pMap);

	return 0;
}
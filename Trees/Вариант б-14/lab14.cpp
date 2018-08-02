#include <iostream>
#include <cassert>

#include "hash_table.hpp"
#include "integer_vector.hpp"

int main()
{
	HashTable * pHT = HashTableCreate();	
	IntegerVector v1;
	IntegerVector v2;
	IntegerVectorInit(v1);
	IntegerVectorInit(v2);
	
	for (int i = 0; i < 5; i++) IntegerVectorPushBack(v1, i);
	for (int i = 0; i < 10; i++) IntegerVectorPushBack(v2, i);
	
	HashTableInsert(*pHT, v1);
	assert(HashTableHasKey(*pHT, v1));

	HashTableInsert(*pHT, v2);
	assert(HashTableNumElements(*pHT) == 2);
	
	HashTableRemoveKey(*pHT, v1);
	assert(!HashTableHasKey(*pHT, v1));

	IntegerVectorDestroy(v1);
	IntegerVectorDestroy(v2);
	HashTableDestroy(pHT); 
	return 0;
}
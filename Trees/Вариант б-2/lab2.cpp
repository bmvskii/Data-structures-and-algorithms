#include <iostream>
#include <math.h>
#include <cassert>

#include "hash_table.hpp"

double function(double _argument)
{
	return std::cos(_argument) * (std::pow(_argument, std::pow(_argument, 3)) / std::sin(_argument));
}

int main()
{
	//создаем хэш-таблицу
	HashTable * pHashTable = HashTableCreate();
	double argument1 = 23.54, argument2 = 44.54;

	//добавляем 2 результата на наших аргументах
	HashTableInsert(*pHashTable,argument1, function(argument1));
	HashTableInsert(*pHashTable,argument2, function(argument2));

	//проверяем , что значеня в хэш-таблице хэшировались
	assert(HashTableGet(*pHashTable, argument1) == function(argument1));
	assert(HashTableGet(*pHashTable, argument2) == function(argument2));
	
	//проверяем количество элементов
	assert(HashTableNumElements(*pHashTable) == 2);

	//удаляем один ключ, проверяем ,что его нет
	HashTableRemoveKey(*pHashTable, argument1);
	assert(HashTableGet(*pHashTable, argument1) == -1);

	//удаляем хэш-таблицу
	HashTableDestroy(pHashTable);
	return 0;
}

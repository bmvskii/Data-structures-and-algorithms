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
	//������� ���-�������
	HashTable * pHashTable = HashTableCreate();
	double argument1 = 23.54, argument2 = 44.54;

	//��������� 2 ���������� �� ����� ����������
	HashTableInsert(*pHashTable,argument1, function(argument1));
	HashTableInsert(*pHashTable,argument2, function(argument2));

	//��������� , ��� ������� � ���-������� ������������
	assert(HashTableGet(*pHashTable, argument1) == function(argument1));
	assert(HashTableGet(*pHashTable, argument2) == function(argument2));
	
	//��������� ���������� ���������
	assert(HashTableNumElements(*pHashTable) == 2);

	//������� ���� ����, ��������� ,��� ��� ���
	HashTableRemoveKey(*pHashTable, argument1);
	assert(HashTableGet(*pHashTable, argument1) == -1);

	//������� ���-�������
	HashTableDestroy(pHashTable);
	return 0;
}

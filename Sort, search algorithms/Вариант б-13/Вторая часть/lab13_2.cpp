#include <iostream>
#include <cassert>

#include "integer_set.hpp"

int main()
{
	//������� � ������������� 3 ���������
	IntegerSet * pSet = IntegerSetCreate();
	IntegerSet * pEqualSet = IntegerSetCreate();
	IntegerSet * pSubset = IntegerSetCreate();

	//��������� 2 ��������� �� 1 �� 10
	for (int i = 0; i < 10; i++) {
		IntegerSetInsertKey(*pSet, i + 1);
		IntegerSetInsertKey(*pEqualSet, i + 1);
	}
		
	//��������� 1 ��������� �� 3 �� 7
	for (int i = 2; i < 7; i++) IntegerSetInsertKey(*pSubset, i + 1);

	//������ � ������ ������ ���� �����
	assert(IntegerSetIsEqual(*pSet, *pEqualSet));
	
	//������ ������ ���� ��������������� � �������, � �������
	assert(IntegerSetIsSubset(*pSet, *pSubset));
	assert(IntegerSetIsSubset(*pEqualSet, *pSubset));

	//������������ �������
	assert(IntegerSetMaxKey(*pSet) == 10);
	assert(IntegerSetMaxKey(*pSubset) == 7);

	//����������� �������
	assert(IntegerSetMinKey(*pSet) == 1);
	assert(IntegerSetMinKey(*pSubset) == 3);

	//���������� ���������
	IntegerSetDestroy(pEqualSet);
	IntegerSetDestroy(pSubset);
	IntegerSetDestroy(pSet);
	return 0;
}
#include <iostream>
#include <cassert>

#include "bstree.hpp"
#include "integer_vector.hpp"

int main()
{
	//������� ������
	BSTree * pBST = BSTreeCreate();
	
	//������� � �������������� 3 �������
	IntegerVector vector1;	IntegerVectorInit(vector1);
	IntegerVector vector2;  IntegerVectorInit(vector2);
	IntegerVector vector3;	IntegerVectorInit(vector3);

	//��������� �������� � �������
	IntegerVectorPushBack(vector1, 5);
	IntegerVectorPushBack(vector1, 4);
	IntegerVectorPushBack(vector1, 3);

	IntegerVectorPushBack(vector2, 1);
	IntegerVectorPushBack(vector2, 2);
	IntegerVectorPushBack(vector2, 3);
	IntegerVectorPushBack(vector2, 4);
	IntegerVectorPushBack(vector2, 5);

	IntegerVectorPushBack(vector3, 2);
	IntegerVectorPushBack(vector3, 3);
	IntegerVectorPushBack(vector3, 4);
	IntegerVectorPushBack(vector3, 5);

	//��������� ������ � ������
	BSTreeInsertKey(*pBST, vector1);
	BSTreeInsertKey(*pBST, vector2);
	BSTreeInsertKey(*pBST, vector3);

	//��������� ��� � ��������� � ��� ������ ����� 1 , � � �������� 2
	assert(!IntegerVectorComparation(BSTreeMaximum(*pBST), vector1));
	assert(!IntegerVectorComparation(BSTreeMinimum(*pBST), vector2));

	//������� ������ ������ � ������� , ��� � ��������� ������ 3 ������
	BSTreeDeleteKey(*pBST, vector1);
	assert(!IntegerVectorComparation(BSTreeMaximum(*pBST), vector3));

	//������� 3 ������
	IntegerVectorDestroy(vector1);
	IntegerVectorDestroy(vector2);
	IntegerVectorDestroy(vector3);

	//������� ������
	BSTreeDestroy(pBST);
	return 0;
}
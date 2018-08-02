#include <iostream>
#include "tree_dynamic.hpp"

void PrintNodeLabel(TreeNode & _node)
{
	TreeNode * pNode = &_node;
	while (pNode != )
	{
		pNode = pNode->m_pParent;
		std::cout << "    ";
	}

	std::cout << pNode->m_label << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Tree * pTree = TreeCreate("����������� ������������ ����������� ���������������� \n ");

	TreeNode * pNodeB = TreeInsertChild(pTree->m_pRoot, "��������� ���");
	TreeNode * pNodeC = TreeInsertChild(pTree->m_pRoot, "��������� ���");
	TreeNode * pNodeD = TreeInsertChild(pTree->m_pRoot, "��������� ���");
	TreeNode * pNodeE = TreeInsertChild(pTree->m_pRoot, "��������� ��");
	TreeNode * pNodeF = TreeInsertChild(pTree->m_pRoot, "��������� ��");
	TreeNode * pNodeG = TreeInsertChild(pTree->m_pRoot, "��������� ����");
	TreeNode * pNodeH = TreeInsertChild(pTree->m_pRoot, "��������� �����");

	TreeInsertChild(pNodeB, "������� ����������� �������������� ����� (���)");
	TreeInsertChild(pNodeB, "������� ������������� �������������� �������������� ������� (����)");
	TreeInsertChild(pNodeB, "������� ������������ �������������� ���������� (���)");
	TreeInsertChild(pNodeB, "������� ���������");

	TreeInsertChild(pNodeC, "������� ���������� ���������� (��)");
	TreeInsertChild(pNodeC, "������� ����������� (���)");
	TreeInsertChild(pNodeC, "������� ������������� ����������� � ���������� ������������� ������������� (��)");
	TreeInsertChild(pNodeC, "������� ������ ���������� (��)");
	TreeInsertChild(pNodeC, "������� ���������� ����������� (��)");

	TreeInsertChild(pNodeD, "������� ��������� ���������� ������ ���������� (����)");
	TreeInsertChild(pNodeD, "������� �����������-��������������� ����������, ������������� � ����������� (�����)");
	TreeInsertChild(pNodeD, "������� ������");
	TreeInsertChild(pNodeD, "������� ������ ����� (��)");

	TreeInsertChild(pNodeE, "������� �������������� ����������� ������ (���)");
	TreeInsertChild(pNodeE, "������� �������������� (��)");
	TreeInsertChild(pNodeE, "������� ����������� ��������� (��)");
	TreeInsertChild(pNodeE, "������� �������������� ���������� (��)");
	TreeInsertChild(pNodeE, "������� ����������� � ���������� (���)");

	TreeInsertChild(pNodeF, "������� �������������������� ��������� (���)");
	TreeInsertChild(pNodeF, "������� �������������-������� ��������� (���)");
	TreeInsertChild(pNodeF, "������� ���������� � ����������� ���������� (���)");

	TreeInsertChild(pNodeG, "������� ����������� ���������� � ������ (���)");
	TreeInsertChild(pNodeG, "������� �������� � �������� ��������� (���)");
	TreeInsertChild(pNodeG, "������� �������������� ��������� (���)");
	
	TreeInsertChild(pNodeH, "������� ����������� ������");
	TreeInsertChild(pNodeH, "������� ��������������� �������������-���������������� ������ (�����)");
	TreeInsertChild(pNodeH, "������� �������������� � �������������� ���������������� ������ (�����)");


	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeDestroy(pTree);

	return 0;
}
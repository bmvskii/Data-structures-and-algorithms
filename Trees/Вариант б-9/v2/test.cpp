#include <iostream>

void PrintNodeLabel(const Tree & _t, int _nodeIndex)
{
	int temp = _nodeIndex;
	while (temp != 0)
	{
		temp = TreeGetParentIndex(_t, temp);
		std::cout << "    ";
	}

	std::cout << TreeGetLabel(_t, _nodeIndex) << std::endl;
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
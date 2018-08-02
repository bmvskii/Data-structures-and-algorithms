#include "tree_dynamic.hpp"
#include <iostream>

// ������� ��������� ���� ��� ������
void PrintNodeLabel(const TreeNode & _node)
{
	std::cout << _node.m_label << ' ';
}

void main() {

	setlocale(LC_ALL, "Rus");

	// �������� ������ � ������ ����� �A�
	Tree * pTree = TreeCreate("�����");

	// ��������� �������� ���� � �����
	TreeNode * pNodeKN = TreeInsertChild(pTree->m_pRoot, "��");
	TreeNode * pNodeKIU = TreeInsertChild(pTree->m_pRoot, "���");
	TreeNode * pNodePMM = TreeInsertChild(pTree->m_pRoot, "���");
	TreeNode * pNodePT = TreeInsertChild(pTree->m_pRoot, "��");
	TreeNode * pNodeET = TreeInsertChild(pTree->m_pRoot, "��");
	TreeNode * pNodeAKT = TreeInsertChild(pTree->m_pRoot, "���");
	TreeNode * pNodeTKBT = TreeInsertChild(pTree->m_pRoot, "����");
	TreeNode * pNodeFZN = TreeInsertChild(pTree->m_pRoot, "���");

	// ��������� �������� ���� � ���� �B�
	TreeInsertChild(pNodeKN, "���");
	TreeInsertChild(pNodeKN, "��");
	TreeInsertChild(pNodeKN, "��");

	// ��������� �������� ���� � ���� �C�
	TreeInsertChild(pNodeKIU, "����");
	TreeInsertChild(pNodeKIU, "��");

	TreeInsertChild(pNodePMM, "��");
	TreeInsertChild(pNodePMM, "���");
	TreeInsertChild(pNodePMM, "��");
	TreeInsertChild(pNodePMM, "��");

	TreeInsertChild(pNodePT, "��");
	TreeInsertChild(pNodePT, "��");
	TreeInsertChild(pNodePT, "����");

	TreeInsertChild(pNodeET, "���");
	TreeInsertChild(pNodeET, "���");
	TreeInsertChild(pNodeET, "��");
	TreeInsertChild(pNodeET, "��");

	TreeInsertChild(pNodeAKT, "����");
	TreeInsertChild(pNodeAKT, "���");
	TreeInsertChild(pNodeAKT, "��");

	TreeInsertChild(pNodeTKBT, "����");
	TreeInsertChild(pNodeTKBT, "���");
	TreeInsertChild(pNodeTKBT, "��");
	TreeInsertChild(pNodeTKBT, "���");

	TreeInsertChild(pNodeFZN, "��");
	TreeInsertChild(pNodeFZN, "��");
	TreeInsertChild(pNodeFZN, "��");
	TreeInsertChild(pNodeFZN, "���");

	// 1) ������
	std::cout << "�����������: ";
	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	// ����������� ������
	TreeDestroy(pTree);
}
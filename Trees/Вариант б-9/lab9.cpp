#include "tree_dynamic.hpp"
#include <iostream>

// Функция посещения узла при обходе
void PrintNodeLabel(const TreeNode & _node)
{
	std::cout << _node.m_label << ' ';
}

void main() {

	setlocale(LC_ALL, "Rus");

	// Создание дерева с меткой корня ‘A’
	Tree * pTree = TreeCreate("ХНУРЭ");

	// Добавляем дочерние узлы к корню
	TreeNode * pNodeKN = TreeInsertChild(pTree->m_pRoot, "КН");
	TreeNode * pNodeKIU = TreeInsertChild(pTree->m_pRoot, "КИУ");
	TreeNode * pNodePMM = TreeInsertChild(pTree->m_pRoot, "ПММ");
	TreeNode * pNodePT = TreeInsertChild(pTree->m_pRoot, "РТ");
	TreeNode * pNodeET = TreeInsertChild(pTree->m_pRoot, "ЭТ");
	TreeNode * pNodeAKT = TreeInsertChild(pTree->m_pRoot, "АКТ");
	TreeNode * pNodeTKBT = TreeInsertChild(pTree->m_pRoot, "ТКВТ");
	TreeNode * pNodeFZN = TreeInsertChild(pTree->m_pRoot, "ФЗН");

	// Добавляем дочерние узлы к узлу ‘B’
	TreeInsertChild(pNodeKN, "ВПС");
	TreeInsertChild(pNodeKN, "КН");
	TreeInsertChild(pNodeKN, "ПИ");

	// Добавляем дочерние узлы к узлу ‘C’
	TreeInsertChild(pNodeKIU, "БИКС");
	TreeInsertChild(pNodeKIU, "КИ");

	TreeInsertChild(pNodePMM, "ЭК");
	TreeInsertChild(pNodePMM, "ИНФ");
	TreeInsertChild(pNodePMM, "ПМ");
	TreeInsertChild(pNodePMM, "СА");

	TreeInsertChild(pNodePT, "АТ");
	TreeInsertChild(pNodePT, "РТ");
	TreeInsertChild(pNodePT, "СТЗИ");

	TreeInsertChild(pNodeET, "БМИ");
	TreeInsertChild(pNodeET, "ЭПС");
	TreeInsertChild(pNodeET, "МН");
	TreeInsertChild(pNodeET, "ОТ");

	TreeInsertChild(pNodeAKT, "АКИТ");
	TreeInsertChild(pNodeAKT, "РЭА");
	TreeInsertChild(pNodeAKT, "СИ");

	TreeInsertChild(pNodeTKBT, "МИВТ");
	TreeInsertChild(pNodeTKBT, "МСС");
	TreeInsertChild(pNodeTKBT, "ТК");
	TreeInsertChild(pNodeTKBT, "УИБ");

	TreeInsertChild(pNodeFZN, "ЭК");
	TreeInsertChild(pNodeFZN, "КИ");
	TreeInsertChild(pNodeFZN, "ПИ");
	TreeInsertChild(pNodeFZN, "ТСМ");

	// 1) Прямой
	std::cout << "Университет: ";
	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	// Уничтожение дерева
	TreeDestroy(pTree);
}
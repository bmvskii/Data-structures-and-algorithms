#include "tree_static.hpp"

#include <iostream>
#include <cassert>

// Функция посещения узла, печатающая его метку
void PrintNodeLabel(const Tree & _t, int _nodeIndex)
{
	std::cout << TreeGetLabel(_t, _nodeIndex) << ' ';
};

int main()
{
	// Создание дерева из 7 узлов
	const int NUM_NODES = 7;
	Tree * pTree = TreeCreate(NUM_NODES);

	// Инициализация меток узлов
	for (int i = 0; i < NUM_NODES; i++)
		TreeSetLabel(*pTree, i, 'A' + i);

	// Инициализация ребер
	TreeSetParentIndex(*pTree, 1, 0); // B -> A
	TreeSetParentIndex(*pTree, 2, 0); // C -> A
	TreeSetParentIndex(*pTree, 3, 0); // D -> A
	TreeSetParentIndex(*pTree, 4, 1); // E -> B
	TreeSetParentIndex(*pTree, 5, 1); // F -> B
	TreeSetParentIndex(*pTree, 6, 2); // G -> C
	
	assert(TreeGetLabel(*pTree, TreeGetLeftmostChildIndex(*pTree, 2)) == 'G');
	assert(TreeGetLabel(*pTree, TreeGetLeftmostChildIndex(*pTree, 1)) == 'E');
	assert(TreeGetLabel(*pTree, TreeGetParentIndex(*pTree, 1)) == 'A');
	assert(TreeGetLabel(*pTree,	TreeGetRightSiblingIndex(*pTree, 2)) == 'D');
	
	// 1) Прямой
	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	// 2) Обратный
	TreeReverseWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	// 3) Симметричный
	TreeSymmetricWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;
	
};
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
	Tree * pTree = TreeCreate("Харьковский национальный университет радиоэлектроники \n ");

	TreeNode * pNodeB = TreeInsertChild(pTree->m_pRoot, "Факультет КИУ");
	TreeNode * pNodeC = TreeInsertChild(pTree->m_pRoot, "Факультет ИТМ");
	TreeNode * pNodeD = TreeInsertChild(pTree->m_pRoot, "Факультет АКТ");
	TreeNode * pNodeE = TreeInsertChild(pTree->m_pRoot, "Факультет КН");
	TreeNode * pNodeF = TreeInsertChild(pTree->m_pRoot, "Факультет ИК");
	TreeNode * pNodeG = TreeInsertChild(pTree->m_pRoot, "Факультет ЭЛБИ");
	TreeNode * pNodeH = TreeInsertChild(pTree->m_pRoot, "Факультет ИРТИЗ");

	TreeInsertChild(pNodeB, "Кафедра электронных вычислительных машин (ЭВМ)");
	TreeInsertChild(pNodeB, "Кафедра автоматизации проектирования вычислительной техники (АПВТ)");
	TreeInsertChild(pNodeB, "Кафедра безопасности информационных технологий (БИТ)");
	TreeInsertChild(pNodeB, "Кафедра философии");

	TreeInsertChild(pNodeC, "Кафедра прикладной математики (ПМ)");
	TreeInsertChild(pNodeC, "Кафедра информатики (ИНФ)");
	TreeInsertChild(pNodeC, "Кафедра экономической кибернетики и управления экономической безопасностью (ЭК)");
	TreeInsertChild(pNodeC, "Кафедра высшей математики (ВМ)");
	TreeInsertChild(pNodeC, "Кафедра социальной информатики (СИ)");

	TreeInsertChild(pNodeD, "Кафедра инженерии встроенных систем управления (ИВСУ)");
	TreeInsertChild(pNodeD, "Кафедра компьютерно-интегрированных технологий, автоматизации и мехатроники (КИТАМ)");
	TreeInsertChild(pNodeD, "Кафедра физики");
	TreeInsertChild(pNodeD, "Кафедра охраны труда (ОТ)");

	TreeInsertChild(pNodeE, "Кафедра информационных управляющих систем (ИУС)");
	TreeInsertChild(pNodeE, "Кафедра системотехники (СТ)");
	TreeInsertChild(pNodeE, "Кафедра программной инженерии (ПИ)");
	TreeInsertChild(pNodeE, "Кафедра искусственного интеллекта (ИИ)");
	TreeInsertChild(pNodeE, "Кафедра медиасистем и технологий (МСТ)");

	TreeInsertChild(pNodeF, "Кафедра инфокоммуникационной инженерии (ИКИ)");
	TreeInsertChild(pNodeF, "Кафедра информационно-сетевой инженерии (ИСИ)");
	TreeInsertChild(pNodeF, "Кафедра метрологии и технической экспертизы (МТЭ)");

	TreeInsertChild(pNodeG, "Кафедра физического воспитания и спорта (ФВС)");
	TreeInsertChild(pNodeG, "Кафедра фотоники и лазерной инженерии (ФЛИ)");
	TreeInsertChild(pNodeG, "Кафедра биомедицинской инженерии (БМИ)");
	
	TreeInsertChild(pNodeH, "Кафедра иностранных языков");
	TreeInsertChild(pNodeH, "Кафедра радиотехнологий информационно-коммуникационных систем (РТИКС)");
	TreeInsertChild(pNodeH, "Кафедра медиаинженерии и информационных радиоэлектронных систем (МИРЭС)");


	TreeDirectWalk(*pTree, &PrintNodeLabel);
	std::cout << std::endl;

	TreeDestroy(pTree);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <clocale>

#include "bstree.hpp"
#include "tests.hpp"

//������� ������ �������� � ����
void print(const BSTree::Node & _pNode, std::ostream & _stream);

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "rus");
	//��������� ��������� ������,���� ��� �������� ����� � ���������� ������
	cmdTest(argc); 
	fileTest(argv[1]);
	BSTreeTest();

	//����� ��� ���������� ������ �� �����
	char text[1024];
	//�������� ���������� �������
	double precision = 10000;
	std::ifstream sourceFile(argv[1]);
	std::ofstream destinationFile(argv[2]);

	BSTree * pTree = BSTreeCreate();
	//����� �������
	clock_t timeOn = clock();
	while (!sourceFile.eof()){
		sourceFile.getline(text, sizeof(text));
		BSTreeInsertKey(*pTree, text);
	}

	//�������������� ����� ������
	BSTreeSymmetricWalk(*pTree, print, destinationFile);
	//����� ���������
	clock_t timeOff = clock();

	std::cout << "����� ������ ������ : " << (double)(timeOff - timeOn) / precision << std::endl;
	
	//����������� ������
	BSTreeDestroy(pTree);
	return 0;
}

void print(const BSTree::Node & _pNode, std::ostream & _stream)
{
	_stream << _pNode.m_key << std::endl;
}

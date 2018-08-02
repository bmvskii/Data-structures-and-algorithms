#include <iostream>
#include <clocale>

#include "hash_table.hpp"

int main()
{
	setlocale(LC_ALL, "rus");

	//������� ���-�������
	HashTable * pHT = HashTableCreate();

	double money;

	int cmd, identifier;
	int currentIdentifier = 1;

	//���� �� ������ 0
	while (true)
	{
		//������ ��������
		std::cout << "$";
		std::cin >> cmd;

		//� ����������� �� �������
		switch (cmd)
		{
		case 0:
			//������� ���-�������
			HashTableDestroy(pHT);
			return 0;
		case 1:
			//����� ���� ��������
			HashTablePrint(*pHT, std::cout); 
			break;
		case 2:
			//�������� ��������
			HashTableInsert(*pHT, currentIdentifier, 0);
			std::cout << "������ ������. ���� : " << currentIdentifier++ << std::endl;
			break;
		case 3:
			//���� ������������ � ���������� �����
			std::cin >> identifier >> money;
			//�������� �����
			if (HashTableGet(*pHT, identifier) == -1) {
				std::cout << "������� �� ����������." << std::endl;
				break;
			}

			if (money < 0){
				std::cout << "������������� �����." << std::endl;
				break;
			}
			//������� �����
			HashTableInsert(*pHT, identifier, money);
			break;
		case 4:
			std::cin >> identifier >> money;
			if (HashTableGet(*pHT, identifier) == -1) {
				std::cout << "������� �� ����������." << std::endl;
				break;
			}
			if (money < 0) {
				std::cout << "������������� ����." << std::endl;
				break;
			}
			//��������� ������� �����
			if (HashTableGet(*pHT, identifier) - money < 0){
				std::cout << "������������ �����." << std::endl;
				break;
			}
			//������� ������
			HashTableInsert(*pHT, identifier, HashTableGet(*pHT, identifier) - money);
			break;
		case 5:
			//�������� �����
			std::cin >> identifier;
			if (HashTableGet(*pHT, identifier) == -1) {
				std::cout << "������� �� ����������." << std::endl;
				break;
			}
			//������� ����
			HashTableRemoveKey(*pHT, identifier);
			break;
		default:
			std::cout << "�������� �������." << std::endl;
			break;
		}
	}
}
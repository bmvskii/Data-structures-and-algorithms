#include <iostream>
#include "hash_table.hpp"

int main()
{
	setlocale(LC_ALL, "rus");
	//������� ���-�������
	HashTable * pHT = HashTableCreate();
	
	char buffer[5];
	int cmd;
	
	//������ ��� ������ � ������
	char loginBuffer[100];
	char passwordBuffer[100];

	//���� �� ������� �������� 3
	while (true)
	{
		//������ �������
		std::cin.getline(buffer, sizeof(buffer));
		cmd = atoi(buffer);

		switch (cmd)
		{
		case 1:
			//��������� ����� � ������
			std::cin.getline(loginBuffer, sizeof(loginBuffer));
			std::cin.getline(passwordBuffer, sizeof(passwordBuffer));

			//������� ����� � ������
			HashTableInsert(*pHT, passwordBuffer, loginBuffer);
			break;
		case 2:
			//��������� ����� � ������
			std::cin.getline(loginBuffer, sizeof(loginBuffer));
			std::cin.getline(passwordBuffer, sizeof(passwordBuffer));

			//���� ���� ����� ������������, �� ������� �����������, � ��������� ������ ���������� �� ����������
			if (HashTableValue(*pHT, passwordBuffer, loginBuffer))
				std::cout << "������," << HashTableValue(*pHT, passwordBuffer, loginBuffer) << std::endl;
			else
				std::cout << "������������ �� ������." << std::endl;
			break;
		case 3:
			//���������� ���-�������
			HashTableDestroy(pHT);
			return 0;
		default:
			std::cout << "�������� �������." << std::endl;
			break;
		}
	}
}
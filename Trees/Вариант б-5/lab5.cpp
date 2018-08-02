#include <iostream>
#include "hash_table.hpp"

int main()
{
	setlocale(LC_ALL, "rus");
	//создаем хэш-таблицу
	HashTable * pHT = HashTableCreate();
	
	char buffer[5];
	int cmd;
	
	//буфера для пароля и логина
	char loginBuffer[100];
	char passwordBuffer[100];

	//пока не введена комманда 3
	while (true)
	{
		//вводим команду
		std::cin.getline(buffer, sizeof(buffer));
		cmd = atoi(buffer);

		switch (cmd)
		{
		case 1:
			//считываем логин и пароль
			std::cin.getline(loginBuffer, sizeof(loginBuffer));
			std::cin.getline(passwordBuffer, sizeof(passwordBuffer));

			//заносим логин и пароль
			HashTableInsert(*pHT, passwordBuffer, loginBuffer);
			break;
		case 2:
			//считываем логин и пароль
			std::cin.getline(loginBuffer, sizeof(loginBuffer));
			std::cin.getline(passwordBuffer, sizeof(passwordBuffer));

			//если есть такой пользователь, то выводим приветствие, в противном случае оповощение об отсутствии
			if (HashTableValue(*pHT, passwordBuffer, loginBuffer))
				std::cout << "Привет," << HashTableValue(*pHT, passwordBuffer, loginBuffer) << std::endl;
			else
				std::cout << "Пользователь не найден." << std::endl;
			break;
		case 3:
			//уничтожаем хэш-таблицу
			HashTableDestroy(pHT);
			return 0;
		default:
			std::cout << "Неверная команда." << std::endl;
			break;
		}
	}
}
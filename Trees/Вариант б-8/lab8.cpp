#include <iostream>
#include <clocale>

#include "hash_table.hpp"

int main()
{
	setlocale(LC_ALL, "rus");

	//создаем хэш-таблицу
	HashTable * pHT = HashTableCreate();

	double money;

	int cmd, identifier;
	int currentIdentifier = 1;

	//пока не введен 0
	while (true)
	{
		//вводим комманды
		std::cout << "$";
		std::cin >> cmd;

		//в зависимости от команды
		switch (cmd)
		{
		case 0:
			//удаляем хэш-таблицу
			HashTableDestroy(pHT);
			return 0;
		case 1:
			//вывод всех клиентов
			HashTablePrint(*pHT, std::cout); 
			break;
		case 2:
			//создание аккаунта
			HashTableInsert(*pHT, currentIdentifier, 0);
			std::cout << "Аккаун создан. Счет : " << currentIdentifier++ << std::endl;
			break;
		case 3:
			//ввод индификатора и количества денег
			std::cin >> identifier >> money;
			//проверка счета
			if (HashTableGet(*pHT, identifier) == -1) {
				std::cout << "Аккаунт не существует." << std::endl;
				break;
			}

			if (money < 0){
				std::cout << "Отрицательная сумма." << std::endl;
				break;
			}
			//вставка денег
			HashTableInsert(*pHT, identifier, money);
			break;
		case 4:
			std::cin >> identifier >> money;
			if (HashTableGet(*pHT, identifier) == -1) {
				std::cout << "Аккаунт не существует." << std::endl;
				break;
			}
			if (money < 0) {
				std::cout << "Отрицательный счет." << std::endl;
				break;
			}
			//проверяем наличие денег
			if (HashTableGet(*pHT, identifier) - money < 0){
				std::cout << "Недостаточно денег." << std::endl;
				break;
			}
			//снимаем деньги
			HashTableInsert(*pHT, identifier, HashTableGet(*pHT, identifier) - money);
			break;
		case 5:
			//удаление счета
			std::cin >> identifier;
			if (HashTableGet(*pHT, identifier) == -1) {
				std::cout << "Аккаунт не существует." << std::endl;
				break;
			}
			//удаляем счет
			HashTableRemoveKey(*pHT, identifier);
			break;
		default:
			std::cout << "Неверная команда." << std::endl;
			break;
		}
	}
}
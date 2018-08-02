#include <iostream>
#include <clocale>

int count(unsigned int _girl)
{
	int counter = 0;
	for (int i = 1; i < 32; i++)
		if (_girl & (1 << (i - 1))) counter++;
	return counter;
}

bool checkDay(int _day)
{
	return _day > 0 && _day < 32;
}

bool checkGirl(int _girl, int _MAX_SIZE)
{
	return _girl > 0 && _girl <= _MAX_SIZE;
}

int main()
{
	setlocale(LC_ALL, "rus");

	const int NUMBER = 3;
	int girlNumber, dayOfEating;

	char command;
	bool flag;

	unsigned int u, intersect, z;
	unsigned int girls[NUMBER];

	for (int i = 0; i < NUMBER; i++) girls[i] = (1 << 31);

	while (true)
	{
		std::cout << "$";
		std::cin >> command;
		switch (command)
		{
		case 'E':
			std::cin >> girlNumber >> dayOfEating;
			if (checkDay(dayOfEating) && checkGirl(girlNumber, NUMBER))
				if (count(girls[girlNumber-1]) >= 4)
					std::cout << "Limit is over." << std::endl;
				else
					girls[girlNumber-1] |= (1 << (dayOfEating - 1));
			else
				std::cout << "Wrong day or number of a girl." << std::endl;
			break;
		case 'S':
			std::cin >> girlNumber;
			if (checkGirl(girlNumber, NUMBER))
				std::cout << count(girls[girlNumber-1]) << std::endl;
			else
				std::cout << "Wrong number of a girl." << std::endl;
			break;
		case 'U':	
			u = (1 << 31);
			flag = false;
			for (int i = 0; i < NUMBER; i++)
				u |= girls[i];
			for (int i = 1; i < 32; i++)
				if (u & (1 << (i - 1))) {
					std::cout << i << std::endl;
					flag = true;
				}

			if (!flag)
				std::cout << "Any same days." << std::endl;
			break;
		case 'I':
			intersect = girls[0];
			flag = false;
			
			for (int i = 1; i < NUMBER; i++)
				intersect &= girls[i];
			
			for (int i = 1; i < 32; i++)
				if (intersect & (1 << (i - 1))) {
					std::cout << i << std::endl;
					flag = true;
				}

			if (!flag)
				std::cout << "Any same days." << std::endl;
			break;

		case 'Z':
			z = girls[0];
			flag = false;

			for (int i = 1; i < NUMBER; i++)
				z |= girls[i];

			for (int i = 1; i < 32; i++)
				if (!(z & (1 << (i - 1)))) {
					std::cout << i << std::endl;
					flag = true;
				}

			if (!flag)
				std::cout << "Any same days." << std::endl;
			break;
		case 'Q':
			return 0;
		default:
			std::cout << "Wrong command. Try again." << std::endl;
			break;
		}
	}

	return 0;
}

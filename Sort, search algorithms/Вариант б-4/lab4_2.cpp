#define _CRT_SECURE_NO_WARNINGS

#include <clocale>
#include <iostream>
#include <cstring>

const char * findName(const char _pData[20][30], const char * _key);

int main()
{
	setlocale(LC_ALL, "rus");

	char lastNames[20][30] = {
		"Anopko",
		"Anopko",
		"Bazilskiy",
		"Bondarenko",
		"Bondarenko",
		"Durnev",
		"Durov",
		"Durov",
		"Galilov",
		"Gavriluk"
		"Gomelev",
		"Guk",
		"Ivanov",
		"Ivanov",
		"Ivanov",
		"Ivanov",
		"Rogovoy",
		"Shegel",
		"Shevchenko",
		"Yaroshenko"
	};

	char buffer[30];
	std::cin.getline(buffer, sizeof(buffer));
	
	if (findName(lastNames, buffer))
	{
		int number = 0;
		for (int i = 0; i < 20; i++)
			if (!strcmp(lastNames[i], buffer))
				number++;
		std::cout << number << std::endl;
	}
	else
		std::cout << "0" << std::endl;

	return 0;
}

const char * findName(const char _pData[20][30], const char * _key) {
	int l = 0, r = 20, m;

	while (l <= r)
	{
		m = l + (r - l) / 2;

		if (strcmp(_pData[m], _key) > 0)
			r = m - 1;
		else if (strcmp(_pData[m], _key) < 0)
			l = m + 1;
		else
			return _pData[m];
	}
	return nullptr;
}
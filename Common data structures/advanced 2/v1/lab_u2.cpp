#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

#include "person_vector.hpp"

int main(int argc, char ** argv)
{
	Vector * vec = new Vector();
	VectorInit(*vec);

	if (argc < 1) {
		std::cout << "Any arguments haven't been entered in command line." << std::endl;
		return -1;
	}

	if (argc < 2 || !atoi(argv[2]))
	{
		std::cout << "The fixed age haven't been entered in command line or it is an uncompatible file." << std::endl;
		return -1;
	}

	int fixedAge = atoi(argv[2]);
	if (fixedAge < 1)
	{
		std::cout << "The fixed age should be a positive number." << std::endl;
		return -1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Wrong path to the file.";
		return -1;
	}

	char buffer[80];
	while (!file.eof())
	{
		file.getline(buffer, sizeof(buffer));
		VectorParseData(*vec, buffer);
	}

	VectorFixedShow(*vec, std::cout, fixedAge);
	
	VectorDestroy(*vec);
	return 0;
}
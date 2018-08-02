#include <iostream>
#include <cstring>
#include <fstream>

#include "vector.hpp"
#include "testing.hpp"

int main(int argc, char ** argv)
{
	testCommandLineArguments(argc, "Testing arguments STATUS OK");
	testCommandLineArgumentsFirstFile(argc, "Testing first file path STATUS OK");
	testCommandLineArgumentsSecondFile(argc, "Testing second file path STATUS OK");
	testCommandLineArgumentsThirdFile(argc, "Testing third file path STATUS OK");

	testCreateFile(argv[1], "Testing first file OPENING STATUS OK");
	testCreateFile(argv[2], "Testing second file OPENING STATUS OK");

	std::ifstream f1(argv[1]), f2(argv[2]);
	std::ofstream out(argv[3]);

	Vector * v = new Vector();
	VectorInit(*v);

	testWrongFileData(*v, f1, "Testing first file STATUS OK.");
	testWrongFileData(*v, f2, "Testing second file STATUS OK.");

	VectorPrint(*v, out);
	VectorDestroy(*v);

	return 0;
}

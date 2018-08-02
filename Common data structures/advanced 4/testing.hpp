#ifndef TESTING_HPP
#define TESTING_HPP

#include "vector.hpp"

#include <cassert>
#include <fstream>

void testCommandLineArguments(int _argc, const char * _text);

void testCommandLineArgumentsFirstFile(int _argc, const char * _text);

void testCommandLineArgumentsSecondFile(int _argc, const char * _text);

void testCommandLineArgumentsThirdFile(int _argc, const char * _text);

void testCreateFile(const char * _path, const char * _text);

void testWrongFileData(Vector & _v, std::ifstream & _s, const char * _text);

#endif // !TESTING_HPP

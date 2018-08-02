#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <cassert>;

void runTests(int _argc, char ** _argv, std::ostream & _s);

void testHasPassedArguments(std::ostream & _s, int _argc);

void testHasPassedFilePath(std::ostream & _s, int _argc);

void testHasPassedFixedAge(std::ostream & _s, int _argc);

void testFixedAgeConvert(std::ostream & _s, char ** _argv);

void testFixedAgeIsPositive(std::ostream & _s, char ** _argv);

void testOpenFile(std::ostream & _s, char * _path);

void testAgeFromFile(std::ostream & _s, char * _src, int _fixedAge);

#endif // !TESTS_HPP

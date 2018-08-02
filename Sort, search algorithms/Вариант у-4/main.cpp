#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <cstring>

#include "string_set.hpp"
#include "test.hpp"

void initCKeyWords(StringSet & _pSet);
void initCppKeyWords(StringSet & _pSet);

int main(int argc, char ** argv)
{
	cmdTest(argc);
	openFileTest(argv[1]);
	setWorkingTest();

	StringSet * pCppSet = StringSetCreate();
	StringSet * pCSet = StringSetCreate();

	//explicit, class, dynamic_cast
	//bool , delete , mutable
	//throw, catch, try, export, operator
	
	initCKeyWords(*pCSet);
	initCppKeyWords(*pCppSet);
	
	std::ifstream in(argv[1]);
	char buffer[512];
	const char lexem[] = " /.,'][{}\|`~!@#$%^&*()-+=;:><\n\t\"?";
	int onlyCpp = 0, bothCppAndC = 0, neitherCppAndC = 0;
	
	while (!in.eof())
	{
		in.getline(buffer, sizeof(buffer));
		char * pCurrent = strtok(buffer, lexem);
		while (pCurrent)
		{
			if (StringSetHasKey(*pCppSet, pCurrent)) 
				onlyCpp++;
			else if (StringSetHasKey(*pCSet, pCurrent)) 
				bothCppAndC++;
			else
				neitherCppAndC++;

			pCurrent = strtok(NULL, lexem);
		}
	}

	std::cout << "ONLY C++ : " << onlyCpp << std::endl;
	std::cout << "BOTH C++ AND C : " << bothCppAndC << std::endl;
	std::cout << "NEITHER C++ AND C : " << neitherCppAndC << std::endl;

	StringSetDestroy(pCppSet);
	StringSetDestroy(pCSet);
	return 0;
}

void initCKeyWords(StringSet & _pSet)
{
	StringSetInsertKey(_pSet, "auto");
	StringSetInsertKey(_pSet, "do");
	StringSetInsertKey(_pSet, "return");
	StringSetInsertKey(_pSet, "typedef");
	StringSetInsertKey(_pSet, "goto");
	StringSetInsertKey(_pSet, "break");
	StringSetInsertKey(_pSet, "double");
	StringSetInsertKey(_pSet, "if");
	StringSetInsertKey(_pSet, "short");
	StringSetInsertKey(_pSet, "union");
	StringSetInsertKey(_pSet, "case");
	StringSetInsertKey(_pSet, "else");
	StringSetInsertKey(_pSet, "inline");
	StringSetInsertKey(_pSet, "signed");
	StringSetInsertKey(_pSet, "unsigned");
	StringSetInsertKey(_pSet, "char");
	StringSetInsertKey(_pSet, "enum");
	StringSetInsertKey(_pSet, "int");
	StringSetInsertKey(_pSet, "sizeof");
	StringSetInsertKey(_pSet, "void");
	StringSetInsertKey(_pSet, "const");
	StringSetInsertKey(_pSet, "extern");
	StringSetInsertKey(_pSet, "long");
	StringSetInsertKey(_pSet, "static");
	StringSetInsertKey(_pSet, "volatile");
	StringSetInsertKey(_pSet, "continue");
	StringSetInsertKey(_pSet, "float");
	StringSetInsertKey(_pSet, "register");
	StringSetInsertKey(_pSet, "struct");
	StringSetInsertKey(_pSet, "while");
	StringSetInsertKey(_pSet, "default");
	StringSetInsertKey(_pSet, "for");
	StringSetInsertKey(_pSet, "restrict");
	StringSetInsertKey(_pSet, "switch");
}

void initCppKeyWords(StringSet & _pSet)
{
	StringSetInsertKey(_pSet, "bool");
	StringSetInsertKey(_pSet, "export");
	StringSetInsertKey(_pSet, "operator");
	StringSetInsertKey(_pSet, "this");
	StringSetInsertKey(_pSet, "virtual");
	StringSetInsertKey(_pSet, "catch");
	StringSetInsertKey(_pSet, "false");
	StringSetInsertKey(_pSet, "private");
	StringSetInsertKey(_pSet, "throw");
	StringSetInsertKey(_pSet, "wchar_t");
	StringSetInsertKey(_pSet, "class");
	StringSetInsertKey(_pSet, "friend");
	StringSetInsertKey(_pSet, "protected");
	StringSetInsertKey(_pSet, "true");
	StringSetInsertKey(_pSet, "const_cast");
	StringSetInsertKey(_pSet, "inline");
	StringSetInsertKey(_pSet, "public");
	StringSetInsertKey(_pSet, "try");
	StringSetInsertKey(_pSet, "delete");
	StringSetInsertKey(_pSet, "mutable");
	StringSetInsertKey(_pSet, "reinterpret_cast");
	StringSetInsertKey(_pSet, "typeid");
	StringSetInsertKey(_pSet, "static_cast");
	StringSetInsertKey(_pSet, "dynamic_cast");
	StringSetInsertKey(_pSet, "namespace");
	StringSetInsertKey(_pSet, "typename");
	StringSetInsertKey(_pSet, "explicit");
	StringSetInsertKey(_pSet, "new");
	StringSetInsertKey(_pSet, "template");
	StringSetInsertKey(_pSet, "using");
}

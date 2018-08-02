#define _CRT_SECURE_NO_WARNINGS

#include "test.hpp"
#include "bstree.hpp"

#include <cstring>
#include <cassert>
#include <iostream>

void testTreeFunctional()
{
	{
		BSTree * BSTCS = BSTreeCreate();

		BSTreeInsertKey(*BSTCS, "AAAAAA");
		BSTreeInsertKey(*BSTCS, "BBBBBB");
		BSTreeInsertKey(*BSTCS, "aaaaaa");
		BSTreeInsertKey(*BSTCS, "CCCCCC");

		assert(BSTreeHasKey(*BSTCS, "AAAAAA"));
		assert(BSTreeHasKey(*BSTCS, "BBBBBB"));
		assert(BSTreeHasKey(*BSTCS, "CCCCCC"));
		assert(BSTreeHasKey(*BSTCS, "aaaaaa"));

		BSTreeDeleteKey(*BSTCS, "aaaaaa");
		assert(!BSTreeHasKey(*BSTCS, "aaaaaa"));

		BSTreeDestroy(BSTCS);
	}
	{
		BSTree * BSTCI = BSTreeCreate(_stricmp);

		BSTreeInsertKey(*BSTCI, "AAAAAA");
		BSTreeInsertKey(*BSTCI, "AaAaAa");
		BSTreeInsertKey(*BSTCI, "AAAaaa");
		BSTreeInsertKey(*BSTCI, "AaaaAA");
		BSTreeInsertKey(*BSTCI, "aaaaaa");

		assert(BSTreeHasKey(*BSTCI, "aaaaaa"));
		assert(!BSTCI->m_pRoot->m_pRight);
		assert(!BSTCI->m_pRoot->m_pLeft);

		BSTreeDestroy(BSTCI);
	}
	{
		BSTree * BSTCS = BSTreeCreate();
		BSTree * BSTCI = BSTreeCreate(_stricmp);

		BSTreeInsertKey(*BSTCS, "AAA");
		BSTreeInsertKey(*BSTCS, "aAA");
		BSTreeInsertKey(*BSTCS, "aaA");

		assert(BSTreeWalker(*BSTCS) == 3);
		assert(BSTreeHasKey(*BSTCS, "AAA"));
		assert(BSTreeHasKey(*BSTCS, "aAA"));
		assert(BSTreeHasKey(*BSTCS, "aaA"));

		BSTreeInsertKey(*BSTCI, "AAA");
		BSTreeInsertKey(*BSTCI, "aAA");
		BSTreeInsertKey(*BSTCI, "aaA");

		assert(BSTreeWalker(*BSTCI) == 1);
		assert(BSTreeHasKey(*BSTCI, "aaa"));

		BSTreeDestroy(BSTCI);
		BSTreeDestroy(BSTCS);
	}
	{
		BSTree * BSTCS = BSTreeCreate();
		BSTree * BSTCI = BSTreeCreate(_stricmp);

		BSTreeInsertKey(*BSTCI, "AAA");
		BSTreeInsertKey(*BSTCI, "BBB");

		BSTreeInsertKey(*BSTCS, "CCC");
		BSTreeInsertKey(*BSTCS, "ccc");
		BSTreeInsertKey(*BSTCS, "EEE");

		BSTreeDeleteKey(*BSTCI, "AAA");
		assert(BSTreeWalker(*BSTCI) == 1);
		assert(!BSTreeHasKey(*BSTCI, "AAA"));

		BSTreeDeleteKey(*BSTCS, "ccc");
		assert(!BSTreeHasKey(*BSTCS, "ccc"));

		BSTreeDestroy(BSTCI);
		BSTreeDestroy(BSTCS);
	}
	{
		BSTree * BSTCI = BSTreeCreate();
		BSTree * BSTCS = BSTreeCreate(_stricmp);

		BSTreeInsertKey(*BSTCI, "AAA");
		BSTreeInsertKey(*BSTCI, "BBB");
		BSTreeInsertKey(*BSTCI, "DDD");
		BSTreeInsertKey(*BSTCI, "ccc");
		BSTreeInsertKey(*BSTCI, "EEE");

		BSTreeInsertKey(*BSTCS, "FFF");
		BSTreeInsertKey(*BSTCS, "GGG");
		BSTreeInsertKey(*BSTCS, "iii");
		BSTreeInsertKey(*BSTCS, "III");
		BSTreeInsertKey(*BSTCS, "jjj");

		assert(!strcmp(BSTreeMinimum(*BSTCI), "AAA"));
		assert(!strcmp(BSTreeMaximum(*BSTCI), "ccc"));

		assert(!strcmp(BSTreeMinimum(*BSTCS), "FFF"));
		assert(!strcmp(BSTreeMaximum(*BSTCS), "jjj"));

		BSTreeDestroy(BSTCI);
		BSTreeDestroy(BSTCS);
	}
}
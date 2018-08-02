#define _CRT_SECURE_NO_WARNINGS
#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

#include <fstream>

typedef int(*CompareFunction) (const char *, const char *);

struct BSTree
{
	CompareFunction function;

	struct Node
	{
		char * m_key;

		Node * m_pParent;
		Node * m_pLeft;
		Node * m_pRight;
	};

	Node * m_pRoot;
};

BSTree * BSTreeCreate(CompareFunction function = strcmp);

void BSTreeDestroy(BSTree * _pTree);

void BSTreeInsertKey(BSTree & _tree, const char * _key);

bool BSTreeHasKey(const BSTree & _tree, const char * _key);

const char * BSTreeMinimum(const BSTree & _tree);

const char * BSTreeMaximum(const BSTree & _tree);

typedef void(*BSTreeWalkFunction) (const BSTree::Node & _node,std::ostream & _stream);

void BSTreeSymmetricWalk(const BSTree & _tree, BSTreeWalkFunction _f, std::ostream & _stream);

void BSTreeDeleteKey(BSTree & _tree, const char * _key);

int BSTreeWalker(BSTree const & _tree);

#endif //  _BSTREE_HPP_
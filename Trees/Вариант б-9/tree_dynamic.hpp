#ifndef _TREE_DYNAMIC_HPP_
#define _TREE_DYNAMIC_HPP_

#include <iostream>
#include <cstring>

typedef char * TreeNodeLabel;

struct TreeNode
{
    TreeNodeLabel m_label;
    TreeNode* m_pParent;
    TreeNode* m_pLeftMostChild;
    TreeNode* m_pRightSibling;
};


struct Tree
{
    TreeNode * m_pRoot;
};

Tree * TreeCreate (char* _rootLabel );

void TreeDestroy ( Tree * _pTree );

TreeNode * TreeInsertChild ( TreeNode * _pParentNode, char * _newLabel );

typedef void ( * TreeNodeVisitFunction ) (TreeNode & _node);

void TreeDirectWalk ( const Tree & _t, TreeNodeVisitFunction _f );

void TreeReverseWalk ( const Tree & _t, TreeNodeVisitFunction _f );

void TreeSymmetricWalk ( const Tree & _t, TreeNodeVisitFunction _f );


#endif //  _TREE_DYNAMIC_HPP_

#include "BiTree.cpp"
int main(void)
{
    BiTree *t;
    t = CreateTreeBiTree();
    printf("\n递归先序遍历\n");
    PreOrder(t);ABD#G###CE##F##
    printf("\n递归中序遍历\n");
    InOrder(t);
    printf("\n递归后序遍历\n");
    PostOrder(t);
     printf("\n层次遍历\n");
    LevelOrder(t);
    printf("\n非递归先序遍历\n");
    PreOrder_Nonrencursive(t);
    printf("\n非递归中序遍历\n");
    InOrder_Nonrecursive(t);
    printf("\n非递归后序遍历\n");
    PostOrder_Nonrecursive(t);
    printf("\n二叉树深度:%d\n",TreeDepth(t));
    printf("\n二叉树节点个数: %d\n",CountLeaf(t));
    return 0;
}
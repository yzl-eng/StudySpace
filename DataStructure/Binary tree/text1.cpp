#include "BiTree.cpp"
int main(void)
{
    BiTree *t;
    t = CreateTreeBiTree();
    printf("\n�ݹ��������\n");
    PreOrder(t);ABD#G###CE##F##
    printf("\n�ݹ��������\n");
    InOrder(t);
    printf("\n�ݹ�������\n");
    PostOrder(t);
     printf("\n��α���\n");
    LevelOrder(t);
    printf("\n�ǵݹ��������\n");
    PreOrder_Nonrencursive(t);
    printf("\n�ǵݹ��������\n");
    InOrder_Nonrecursive(t);
    printf("\n�ǵݹ�������\n");
    PostOrder_Nonrecursive(t);
    printf("\n���������:%d\n",TreeDepth(t));
    printf("\n�������ڵ����: %d\n",CountLeaf(t));
    return 0;
}
#include "BiTree.cpp"
int main(void)
{
    BiTree *t;
    ElemType x;
    t = CreateTreeBiTree();
    printf("\n�ݹ��������\n");
    PreOrder(t);
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
    printf("\n���������:%d\n", TreeDepth(t));
    printf("\n���������:%d\n", TreeWidth(t));
    printf("\n�������ڵ����: %d\n", CountLeaf(t));
    printf("\n�������������������ڵ�");
    printf("\n�ݹ��������\n");
    PreOrder(Change_Node(t));
    printf("\n��Ϊ��������Ϊ%d\n", Degrees_2(t));
    printf("\n����x���\n");
    getchar();
    scanf("%c", &x);
    printf("�����Ƚڵ�Ϊ\n");
    Find_Node(t, x);
    return 0;
}
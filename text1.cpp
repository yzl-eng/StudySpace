#include "BiTree.cpp"
int main(void)
{
    BiTree *t;
    ElemType x;
    t = CreateTreeBiTree();
    printf("\n递归先序遍历\n");
    PreOrder(t);
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
    printf("\n二叉树深度:%d\n", TreeDepth(t));
    printf("\n二叉树宽度:%d\n", TreeWidth(t));
    printf("\n二叉树节点个数: %d\n", CountLeaf(t));
    printf("\n交换二叉树左右子树节点");
    printf("\n递归先序遍历\n");
    PreOrder(Change_Node(t));
    printf("\n度为二结点个数为%d\n", Degrees_2(t));
    printf("\n查找x结点\n");
    getchar();
    scanf("%c", &x);
    printf("其祖先节点为\n");
    Find_Node(t, x);
    return 0;
}
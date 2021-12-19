#include <stdio.h>
#include <malloc.h>
#include <cstdlib>
#include <string.h>
#define M 20
#define ERROR 0
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *left, *right;
} BiTree;

//二叉树的创建算法
BiTree *CreateTreeBiTree()
{
    BiTree *t;
    char ch;
    scanf("%c", &ch);
    if (ch != '#')
    {
        t = (BiTree *)malloc(sizeof(BiTree));
        t->data = ch;
        t->left = CreateTreeBiTree();
        t->right = CreateTreeBiTree();
    }
    else
        t = NULL;
    return t;
}

//递归先序遍历(DLR)
void PreOrder(BiTree *t)
{
    if (t != NULL)
    {
        printf(" %c", t->data);
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

//递归中序遍历(LDR)
void InOrder(BiTree *t)
{
    if (t != NULL)
    {
        InOrder(t->left);
        printf(" %c", t->data);
        InOrder(t->right);
    }
}

//递归后序遍历(LRD)
void PostOrder(BiTree *t)
{
    if (t != NULL)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        printf(" %c", t->data);
    }
}

//层次遍历
void LevelOrder(BiTree *t)
{
    BiTree *p;
    BiTree *queue[M];
    int front, rear;
    if (t == NULL)
        return;
    rear = 0;
    front = rear;
    queue[rear] = t;
    rear = (rear + 1) % M;
    while (front != rear)
    {
        p = queue[front];
        front = (front + 1) % M;
        printf(" %c", p->data);
        if (p->left != NULL)
        {
            queue[rear] = p->left;
            rear = (rear + 1) % M;
        }
        if (p->right != NULL)
        {
            queue[rear] = p->right;
            rear = (rear + 1) % M;
        }
    }
}

//非递归先序排列
void PreOrder_Nonrencursive(BiTree *t)
{
    BiTree *s[M], *p;
    int top = 0;
    if (t != NULL)
    {
        p = t;
        do
        {
            while (p != NULL)
            {
                printf(" %c", p->data);
                s[top] = p;
                top++;
                p = p->left;
            }
            if (top > 0)
            {
                top--;
                p = s[top];
                p = p->right;
            }
        } while (p != NULL || top > 0);
    }
}

//非递归中序遍历
void InOrder_Nonrecursive(BiTree *t)
{
    BiTree *s[M], *p;
    int top = 0;
    if (t != NULL)
    {
        p = t;
        do
        {
            while (p != NULL)
            {
                s[top] = p;
                top++;
                p = p->left;
            }
            if (top > 0)
            {
                top--;
                p = s[top];
                printf(" %c", p->data);
                p = p->right;
            }
        } while (p != NULL || top > 0);
    }
}

//非递归后序遍历
typedef struct
{
    BiTree *ptr;
    char tag;
} seqstack;

//交换左右子树结点
BiTree *Change_Node(BiTree *t)
{
    BiTree *temp;
    BiTree *left;
    BiTree *right;
    if(t->left!=NULL&&t->right!=NULL)
    {
        left=t->left;
        right=t->right;
        left=Change_Node(left);
        right=Change_Node(right);
        temp=t->left;
        t->left=t->right;
        t->right=temp;
        return t;
    }

}
void PostOrder_Nonrecursive(BiTree *t)
{
    BiTree *p;
    seqstack s[M], q;
    int top = 0;
    if (t != NULL)
    {
        p = t;
        do
        {
            while (p != NULL)
            {
                q.ptr = p;
                q.tag = 'L';
                s[top] = q;
                top++;
                p = p->left;
            }
            top--;
            q = s[top];
            p = q.ptr;
            while (q.tag == 'R')
            {
                printf(" %c", p->data);
                if (p == t)
                    break;
                if (top > 0)
                {
                    top--;
                    q = s[top];
                    p = q.ptr;
                }
            }
            if (q.tag == 'L')
            {
                q.ptr = p;
                q.tag = 'R';
                s[top] = q;
                top++;
                p = p->right;
            }
        } while (top > 0);
    }
}

//求二叉树深度算法
int TreeDepth(BiTree *t)
{
    int hl, hr, max;
    if (t != NULL)
    {
        hl = TreeDepth(t->left);
        hr = TreeDepth(t->right);
        max = hl > hr ? hl : hr;
        return max + 1;
    }
    else
        return 0;
}

//已知先序和中序推测后续序列
BiTree *CalculatePostOrder(char preorder[], char inorder[])
{
    BiTree *t;
    int l;
    l=strlen(preorder);
    if (strlen(preorder) == strlen(inorder))
        return ERROR;
    else
    {
        
        char postorder[l];
        postorder[l-1]=preorder[1];
        
    }
}

//统计二叉树中度为二节点个数
int Degrees_2(BiTree *t)
{
    if(t==NULL)
        return ERROR;
    if(t->left!=NULL&&t->right!=NULL)
        return  (1+Degrees_2(t->left)+Degrees_2(t->right));
    else
        return (Degrees_2(t->left)+Degrees_2(t->right));
}
//查找x结点，并输出所有祖先
void Find_Node(BiTree *t,ElemType x)
{
    BiTree *p;
    seqstack s[M], q;
    int top = 0;
    if (t != NULL)
    {
        p = t;
        do
        {
            while (p != NULL)
            {
                q.ptr = p;
                q.tag = 'L';
                s[top] = q;
                top++;
                p = p->left;
            }
            top--;
            q = s[top];
            p = q.ptr;
            while (q.tag == 'R')
            {
               if(x==p->data)
                {
                    if(top==0)
                        printf("%c",t->data);
                    for(int i=0;i<top;i++)
                    {
                        printf("%c ",s[i].ptr->data);
                    }
                   return; 
                }
                if (p == t)
                    break;
                if (top > 0)
                {
                    top--;
                    q = s[top];
                    p = q.ptr;
                }
            }
            if (q.tag == 'L')
            {
                q.ptr = p;
                q.tag = 'R';
                s[top] = q;
                top++;
                p = p->right;
            }
        } while (top > 0);
    }
    
}
int width[M] = {0}; //加入这棵树的最大高度不超过10
int maxWidth = 0;
int floor = 1;

//求二叉树宽度(所有层中结点最大值)
int TreeWidth(BiTree *t)
{
    int n;
    if (t)
    {
        if (floor == 1)
        { //如果访问的是根节点的话，第一层节点++;
            width[floor]++;
            maxWidth = 1;
            floor++;
            if (t->left)
                width[floor]++;
            if (t->right)
                width[floor]++;
        }
        else
        {
            floor++;
            if (t->left)
                width[floor]++;
            if (t->right)
                width[floor]++;
        }
        if (maxWidth < width[floor])
            maxWidth = width[floor];
        n = floor;
        TreeWidth(t->left);
        floor = n; //返回递归前的层数
        TreeWidth(t->right);
    }
    return maxWidth;
}

//统计二叉树叶子节点个数
int CountLeaf(BiTree *t)
{
    BiTree *s[M], *p;
    int cnt = 0, top = 0;
    if (t != NULL)
    {
        p = t;
        do
        {
            while (p != NULL)
            {
                if (p->left == NULL && p->right == NULL)
                    cnt++;
                s[top] = p;
                top++;
                p = p->right;
            }
            if (top > 0)
            {
                top--;
                p = s[top];
                p = p->right;
            }
        } while (p != NULL || top > 0);
    }
    return cnt;
}

#include <stdio.h>
#include<malloc.h>
#include<cstdlib>
#define M 20
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *left, *right;
} BiTree;

//�������Ĵ����㷨
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

//�ݹ��������(DLR)
void PreOrder(BiTree *t)
{
    if (t != NULL)
    {
        printf("%c", t->data);
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

//�ݹ��������(LDR)
void InOrder(BiTree *t)
{
    if (t != NULL)
    {
        InOrder(t->left);
        printf("%c", t->data);
        InOrder(t->right);
    }
}

//�ݹ�������(LRD)
void PostOrder(BiTree *t)
{
    if (t != NULL)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        printf("%c", t->data);
    }
}

//��α���
void LevelOrder(BiTree *t)
{
    BiTree *p;
    BiTree *queue[M];
    int front, rear;
    if (t == NULL)
        return;
    front = rear;
    queue[rear] = t;
    rear = (rear + 1) % M;
    while (front != rear)
    {
        p = queue[front];
        front = (front + 1) % M;
        printf("%c", p->data);
        if (p->left != NULL)
        {
            queue[rear] = p->left;
            rear = (rear + 1) % M;
        }
    }
}

//�ǵݹ���������
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

//�ǵݹ��������
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

//�ǵݹ�������
typedef struct
{
    BiTree *ptr;
    char tag;
} seqstack;
void PostOrder_Nonrecursive(BiTree *t)
{
    BiTree *p;
    seqstack s[M], q;
    int top = 0;
    if (t != NULL)
    {
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

//�����������㷨
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

//ͳ�ƶ�����Ҷ�ӽڵ����
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

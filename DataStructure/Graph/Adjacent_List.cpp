#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkQueue.c"

#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR 0
#define MAX_NAME 10
#define TRUE 1
#define FALSE 0

//图的邻接表存储结构
typedef int InfoType;
typedef char VertexType[MAX_NAME];
typedef int Status;
typedef int Boolean;
typedef enum
{
    DG,
    DN,
    AG,
    AN
} GraphKind; //有向图，有向网，无向图，无向网

typedef struct ArcNode
{
    int adjvex;              //该弧所指向的顶点的位置
    InfoType *info;          //网的权值的指针
    struct ArcNode *nextarc; //指向下一弧的指针
} ArcNode;                   //表结点

typedef struct
{
    VertexType data;   //顶点信息
    ArcNode *firstarc; //第一个表结点的地址，指向第一条依附顶点的弧
} VNode;               //表结点

typedef struct
{
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum; //图的当前顶点数和弧数
    int kind;           //图的种类标志
} ALGraph;

//求顶点位置算法
int LocateVex(ALGraph G, VertexType u)
{
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (strcmp(u, G.vertices[i].data) == 0)
            return i;
    return -1;
}

//求顶点信息算法
VertexType *GetVex(ALGraph *G, int v)
{
    if (v >= G->vexnum || v < 0)
        exit(ERROR);
    return &G->vertices[v].data;
}

//对顶点赋新值的算法
Status PutVex(ALGraph *G, VertexType v, VertexType value)
{
    int i;
    i = LocateVex(*G, v);
    if (i > -1)
    {
        strcpy((*G).vertices[i].data, value);
        return OK;
    }
    return ERROR;
}

//求顶点的第一个邻接顶点序号的算法
int FirstAdjVex(ALGraph G, VertexType v)
{
    ArcNode *p;
    int i;
    i = LocateVex(G, v); //i为顶点v在图G中的序号
    p = G.vertices[i].firstarc;
    if (p)
        return p->adjvex;
    else
        return -1;
}

//求顶点v相对于某顶点w的下一个邻接顶点序号的算法
int NextAdjvex(ALGraph G, VertexType v, VertexType w)
{
    ArcNode *p;
    int v1, w1;
    v1 = LocateVex(G, v);
    w1 = LocateVex(G, w);
    p = G.vertices[v1].firstarc;
    while (p && p->adjvex != w1) //指针怕不空且所指表结点不是w
    {
        p = p->nextarc;
    }
    if (!p || !p->nextarc) //没找到w或w最后一个邻接点
        return -1;
    else
        return p->nextarc->adjvex; //返回v（相对于w）的下一个邻接顶点的序号
}

//插入新顶点的算法
void InsertVex(ALGraph *G, VertexType v)
{
    strcpy((*G).vertices[(*G).vexnum].data, v); //将新顶点插入到顶点数组的数据域
    (*G).vertices[(*G).vexnum].firstarc = NULL;
    (*G).vexnum++; //图G的顶点数加1
}

//删除顶点算法
Status DeleteVex(ALGraph *G, VertexType v)
{
    int i, j;
    ArcNode *p, *q;
    j = LocateVex(*G, v); //j是顶点v的序号
    if (j < 0)            //v不是图G的顶点
        return ERROR;
    p = (*G).vertices[j].firstarc; //删除以v为出度的弧或边
    while (p)
    {
        q = p;
        p = p->nextarc;
        if ((*G).kind % 2) //判断是否为网
            free(q->info);
        free(q);
        (*G).arcnum--; //弧或边数减1
    }
    (*G).vexnum--;                    //顶点数减1
    for (i = j; i < (*G).vexnum; i++) //顶点v后面的顶点前移
        (*G).vertices[i] = (*G).vertices[i + 1];
    for (i = 0; i < (*G).vexnum; i++)
    {
        //删除以v为入度的弧或边且必要时修改表结点的顶点位置值
        p = (*G).vertices[i].firstarc;
        while (p)
        {
            if (p->adjvex == j)
            {
                if (p == (*G).vertices[i].firstarc) //待删除结点的第一个结点
                {
                    (*G).vertices[i].firstarc = p->nextarc;
                    if ((*G).kind % 2)
                        free(p->info);
                    free(p->info);
                    p = ((*G).vertices[i].firstarc);
                    if ((*G).kind < 2)
                        (*G).arcnum--;
                }
                else
                {
                    q->nextarc = p->nextarc;
                    if ((*G).kind % 2)
                        free(p->info);
                    free(p);
                    p = q->nextarc;
                    if ((*G).kind < 2) //有向
                        (*G).arcnum--;
                }
            }
            else
            {
                if (p->adjvex > j)
                    p->adjvex--; //修改表结点的顶点的位置
                q = p;
                p = p->nextarc;
            }
        }
    }
    return OK;
}

//插入新弧的算法
Status InsertArc(ALGraph *G, VertexType v, VertexType w)
{
    ArcNode *p;
    int w1, i, j;
    i = LocateVex(*G, v);
    j = LocateVex(*G, w);
    if (i < 0 || j < 0)
        return ERROR;
    (*G).arcnum++; //图G的弧或边的数目加1
    if ((*G).kind % 2)
    {
        printf("请输入弧（边）%s->%s的权值：", v, w);
        scanf("%d", &w1);
    }
    else
        p->info = NULL;
    p->nextarc = (*G).vertices[i].firstarc;
    (*G).vertices[i].firstarc = p;
    if ((*G).kind >= 2) //无向，生成另一个表结点
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = i;
        if ((*G).kind == 3)
        {
            p->info = (int *)malloc(sizeof(int));
            *(p->info) = w1;
        }
        else
            p->info = NULL;
        p->nextarc = (*G).vertices[j].firstarc; //插在表头
        (*G).vertices[j].firstarc = p;
    }
    return OK;
}

//删除弧的算法
Status DeleteArc(ALGraph *G, VertexType v, VertexType w)
{
    ArcNode *p, *q;
    int i, j;
    i = LocateVex(*G, v);
    j = LocateVex(*G, w);
    if (i < 0 || j < 0 || i == j)
        return ERROR;
    p = (*G).vertices[i].firstarc; //p指向顶点v的第一条出弧
    while (p && p->adjvex != j)    //怕不空且所指之弧不是待删除弧<v,w>
    {
        q = p;
        p = p->nextarc;
    }
    if (p && p->adjvex == j) //找到弧<v,w>
    {
        if (p == (*G).vertices[i].firstarc)         //p所指是第一条弧
            (*G).vertices[i].firstarc = p->nextarc; //指向下一条弧
        else
            q->nextarc = p->nextarc; //指向下一条弧
        if ((*G).kind % 2)
            free(p->info);
        free(p);
        (*G).arcnum--;
    }
    if ((*G).kind >= 2)
    {
        p = (*G).vertices[j].firstarc;
        while (p && p->adjvex != i) //p不为空且所指之弧不是待删除弧<w,v>
        {
            q = p;
            p = p->nextarc;
        }
        if (p && p->adjvex == i)
        {
            if (p == (*G).vertices[j].firstarc)
                (*G).vertices[j].firstarc = p->nextarc;
            else
                q->nextarc = p->nextarc;
            if ((*G).kind == 3)
                free(p->info);
            free(p);
        }
    }
    return OK;
}

//图的销毁算法
void DestroyGraph(ALGraph *G)
{
    int i;
    ArcNode *p, *q;
    (*G).vexnum = 0;
    (*G).arcnum = 0;
    for (i = 0; i < (*G).vexnum; ++i)
    {
        p = (*G).vertices[i].firstarc;
        (*G).vertices[i].firstarc = NULL;
        while (p)
        {
            q = p->nextarc;
            if ((*G).kind % 2)
                free(p->info);
            free(p);
            p = q;
        }
    }
}

//图的邻接表存储结构创建算法
Status CreateGraph(ALGraph *G)
{
    int i, j, k;
    int w; //权值
    VertexType va, vb;
    ArcNode *p;
    printf("请输入图的类型(有向图：0，有向网：1，无向图：2，无向网：3)：");
    scanf("%d", &(*G).kind);
    printf("请输入图的顶点数，边数：");
    scanf("%d,%d", &(*G).vexnum, &(*G).arcnum);
    printf("请输入%d个顶点的值(<%d个字符>):\n", (*G).vexnum, MAX_NAME);
    for (i = 0; i < (*G).vexnum; ++i) //构造顶点向量
    {
        scanf("%s", (*G).vertices[i].data);
        (*G).vertices[i].firstarc = NULL;
    }
    if ((*G).kind == 1 || (*G).kind == 3)
        printf("请顺序输入每条弧(边)的权值，弧尾和弧头(以空格作为间隔)：\n");
    else
        printf("请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n");
    for (k = 0; k < (*G).arcnum; ++k) //构造表结点链表
    {
        if ((*G).kind == 1 || (*G).kind == 3)
            scanf("%d%s%s", &w, va, vb);
        else
            scanf("%s%s", va, vb);
        i = LocateVex(*G, va);
        j = LocateVex(*G, vb);
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j;
        if ((*G).kind == 1 || (*G).kind == 3)
        {
            p->info = (int *)malloc(sizeof(int));
            *(p->info) = w;
        }
        else
            p->info = NULL;
        p->nextarc = (*G).vertices[i].firstarc;
        (*G).vertices[i].firstarc = p;
        if ((*G).kind >= 2)
        {
            p = (ArcNode *)malloc(sizeof(ArcNode));
            p->adjvex = i;
            if ((*G).kind == 3)
            {
                p->info = (int *)malloc(sizeof(int));
                *(p->info) = w;
            }
            else
                p->info = NULL;
            p->nextarc = (*G).vertices[j].firstarc;
            (*G).vertices[j].firstarc = p;
        }
    }
    return OK;
}

//图的邻接表存储结构打印输出算法
void Display(ALGraph G)
{
    int i;
    ArcNode *p;
    switch (G.kind)
    {
    case DG:
        printf("有向图\n");
        break;
    case DN:
        printf("有向网\n");
        break;
    case AG:
        printf("有向图\n");
        break;
    case AN:
        printf("无向网\n");
    }
    printf("%d个顶点:\n", G.vexnum);
    for (i = 0; i < G.vexnum; ++i)
        printf("%s", G.vertices[i].data);
    printf("\n%d条弧(边):\n", G.arcnum);
    for (i = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstarc;
        while (p)
        {
            if (G.kind <= 1)
            {
                printf("%s->%s", G.vertices[i].data, G.vertices[p->adjvex].data);
                if (G.kind == DN)
                    printf(":%d", *(p->info));
            }
            else //无向(避免输出两次)
            {
                if (i < p->adjvex)
                {
                    printf("%s->%s", G.vertices[i].data, G.vertices[p->adjvex].data);
                    if (G.kind == AN)
                        printf(":%d", *(p->info));
                }
                p = p->nextarc;
            }
            printf("\n");
        }
    }
}

//邻接表存储结构上的广度优先遍历算法BFS
void BFSTraverse(ALGraph G, void (*Visit)(char *))
{
    int v, u, w;
    VertexType u1, w1;
    LinkQueue Q;
    Boolean visited[MAX_VERTEX_NUM];
    for (v = 0; v < G.vexnum; ++v)
        visited[v] = ERROR;
    InitQueue(&Q);
    for (v = 0; v < G.vexnum; v++)
        if (!visited[v])
        {
            visited[v] = OK;
            Visit(G.vertices[v].data);
            EnQueue(&Q, v);
            while (!QueueEmpty(&Q))
            {
                DeQueue(&Q, &u);
                strcpy(u1, *GetVex(&G, v));
                w = FirstAdjVex(G, u1);
                for (; w >= 0; w >= NextAdjvex(G, u1, strcpy(w1, *GetVex(G, w))))
                {
                    if (!visited[w])
                    {
                        visited[w] = OK;
                        Visit(G.vertices[w].data);
                        EnQueue(&Q, w);
                    }
                }
            }
        }
    printf("\n");
}

//邻接表存储结构上的深度优先遍历的非递归算法
Boolean visited[MAX_VERTEX_NUM] = {0};
void DFSTraverse(ALGraph G, VertexType v0, void (*Visit)(VertexType))
{
    int S[MAX_VERTEX_NUM];
    int top = -1;
    int v, w;
    VertexType *vt1, *vt2;
    for (v = 0; v < G.vexnum; v++)
        visited[v] = FALSE;
    v = LocateVex(G, v0);
    S[++top] = v;
    while (top1 = -1)
    {
        v = S[top--];
        if (!visited[v])
        {
            Visit(*GetVex(G, v));
            visited[v] = 1;
        }
        vt1 = GetVex(G, v);
        w = FirstAdjVex(G, *vt1);
        vt2 = GetVex(G, w);
        while (w != -1)
        {
            if (!visited[w])
            {
                s[top++] = w;
                w = NextAdjvex(G, *vt1, *GetVex(G, w));
            }
        }
    }
    printf("\n");
}
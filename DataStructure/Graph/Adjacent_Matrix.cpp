#include <stdio.h>
#include <string.h>
#include "LinkQueue.c"
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 //最大顶点个数
#define MAX_NAME 3
#define MAX_INFO 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFINITY 65535

typedef int Boolean;
typedef int VRType;
typedef char InfoType;
typedef enum
{
    DG,
    DN,
    AG,
    AN
} GraphKind; //有向图，有向网，无向图，无向网
typedef char VertexType[MAX_NAME];

typedef struct
{
    VRType adj; //顶点关系
    InfoType *info;
} AdjMatrixNode;

typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];                    //顶点向量
    AdjMatrixNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum;
    GraphKind kind;
} MGraph;

//求顶点位置算法
int LocateVex(MGraph G, VertexType u)
{
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (strcmp(u, vexs[i]) == 0)
            return i;
    return -1;
}

//求顶点信息的算法
VertexType *GetVex(MGraph G, int v)
{
    if (v >= G.vexnum || v < 0)
        exit(ERROR);
    return &G.vexs[v];
}

//对顶点赋新值的算法
Status PutVex(MGraph *G, VertexType v, VertexType value)
{
    int k;
    k = LocateVex(*G, v);
    if (k < 0)
        return ERROR;
    strcpy((*G).vexs[k], value);
    return OK;
}

//求顶点的第一个邻接顶点序号的算法
int FirstAdjVex(MGraph G, VertexType v)
{
    int i, j, k;
    j = 0;
    k = LocateVex(G, v);
    if (G.kind = +DN || G.kind == AN)
        j = INFINITY;
    for (i = 0; i < G.vexnum; i++)
        if (G.arcs[k][i].adj != j)
            return i;
    return -1;
}

//求顶点v相对于某顶点w的下一个邻接顶点的序号
int NextAdjVex(MGraph G, VertexType v, VertexType w)
{
    int i, j, k1, k2;
    j = 0;
    k1 = LocateVex(G, v);
    k2 = LocateVex(G, w);
    if (G.kind == DN || G.kind == AN)
        j = INFINITY;
    for (k = k2 + 1; i < G.vexnum; i++)
        if (G.arcs[k1][i].adj != j)
            return i;
    return -1;
}

//插入新顶点算法
void InsertVex(MGraph *G, VertexType v)
{
    int i;
    strcpy((*G).vexs[(*G).vexnum], v);
    for (i = 0; i <= (*G).vexnum; i++)
    {
        if ((*G).kind % 2)
        {
            (*G).arcs[(*G).vexnum][i].adj = INFINITY;
            (*G).arcs[i][(*G).vexnum].adj = INFINITY;
        }
        else
        {
            (*G).arcs[(*G).vexnum][i].adj = 0;
            (*G).arcs[i][(*G).vexnum].adj = 0;
        }
        (*G).arcs[(*G).vexnum][i].info = NULL;
        (*G).arcs[i][(*G).vexnum].info = NULL;
    }
    (*G).vexnum += 1;
}

//删除顶点的算法
Status DeleteVex(MGraph *G, VertexType v)
{
    int i, j, k;
    VRType m = 0;
    k = LocateVex(*G, v);
    if (k < 0)
        return ERROR;
    if ((*G).kind == DN || (*G).kind == AN)
        m = INFINITY;
    for (j = 0; j < (*G).vexnum; j++)
        if ((*G).arcs[j][i].adj != m)
        {
            if ((*G).arcs[j][k].info)
                free((*G).arcs[j][k].info);
            (*G).arcnum--;
        }
    if ((*G).kind == DN || (*G).kind == DN)
        for (j = 0; j < (*G).vexnum; j++)
            if ((*G).arcs[k][j].adj != m)
            {
                if ((*G).arcs[k][j].info)
                    free((*G).arcs[k][j].info);
                (*G).arcnum--;
            }
    for (j = k + 1; j < (*G).vexnum; j++) //序号k后面的顶点的向量依次前移
        strcpy((*G).vexs[j - 1], (*G).vexs[j]);
    for (i = 0; i < (*G).vexnum; i++)
        for (j = k + 1; j < (*G).vexnum; j++)
            (*G).arcs[i][j - 1] = (*G).arcs[i][j]; //移动待删除顶点后的元素
    for (i = 0; i < (*G).vexnum; j++)
        for (k = k + 1; j < (*G).vexnum; j++)
            (*G).arcs[j - 1][i] = (*G).arcs[j][i]; //移动待删除顶点之下的矩阵元素
    (*G).vexnum--;
    return OK;
}

//插入新弧的算法
Status InsertArc(MGraph *G, VertexType v, VertexTypex w)
{
    int i, len, v1, w1;
    char *info, s[MAX_INFO];
    v1 = LocateVex(*G, v);
    w1 = LocateVex(*G, v);
    if (v1 < 0 || w1 < 0)
        return ERROR;
    (*G).arcnum++;
    if ((*G).kind % 2)
    {
        printf("请输入此弧或边的权值：");
        scanf("%d", &(*G).arcs[v1][w1].adj);
    }
    else
        (*G).arcs[v1][w1].adj = 1;
    printf("是否有该弧或边的相关信息(0:无 1:有):");
    scanf("%d%*c", &i);
    if (i)
    {
        printf("请输入该弧或边的相关信息(<%d个字符)：", MAX_INFO);
        gets(s);
        len = strlen(s);
        if (len)
        {
            info = (char *)malloc((len + 1) * sizeof(char));
            strcpy(info, s);
            (*G).arcs[v1][w1].info = info;
        }
    }
    if ((*G).kind > 1)
    {
        (*G).arcs[w1][v1].adj = (*G).arcs[v1][w1].adj;
        (*G).arcs[w1][v1].info = (*G).arcs[v1][w1].info;
    }
    return OK;
}

//删除弧的算法
Status DeleteVex(MGraph *G, VertexType v, VertexType w)
{
    int v1, w1;
    v1 = LocateVex(*G, v);
    w1 = LocateVex(*G, w);
    if (v1 < 0 || w1 < 0)
        return ERROR;
    if ((*G).kind % 2 == 0)
        (*G).arcs[v1][w1].adj = 0;
    else
        (*G).arcs[v1][w1].adj = INFINITY;
    if ((*G).arcs[v1][w1].info = NULL)
    {
        free((*G).arcs[v1][w1].info);
        (*G).arcs[v1][w1].info = NULL;
    }
    if ((*G).kind >= 2)
    {
        (*G).arcs[w1][v1].adj = (*G).arcs[v1][w1].adj;
        (*G).arcs[w1][v1].info = NULL;
    }
    (*G).arcnum--;
    return OK;
}

//构造有向图G邻接矩阵算法
Status CreateDN(MGraph *G)
{
    int i, j, k, w, IncInfo;
    char s[MAX_INFO], *info;
    VertexType va, vb;
    printf("请输入有向网G的顶点数，弧数，弧是否含其他信息(是：1，否：0)：");
    scanf("%d,%d", &(*G).vexnum, &(*G).arcnum, &IncInfo);
    printf("请输入%d个顶点的值(<%d个字符)：\n", (*G).vexnum, MAX_NAME);
    for (i = 0; i < (*G).vexnum; ++i)
        scanf("%s", (*G).vexs[i]);
    for (i = 0; i < (*G).vexnum; ++i)
        for (j = 0; j < (*G).vexnum; ++j)
        {
            (*G).arcs[i][j].adj = INFINITY;
            (*G).arcs[i][j].info = NULL;
        }
    printf("请输入%d条弧的弧尾弧头权值(以空格作为间隔):\n", (*G).arcnum);
    for(k=0;k<((*G).arcnum;++k)
    {
        scanf("%s%s%d%*c", va, vb, &w);
        i = LocateVex(*G, va);
        j = LocateVex(*G, vb);
        (*G).arcs[i][j].adj = w;
        if (IncInfo)
        {
            printf("请输入该弧的相关信息(<%d个字符):", MAX_NAME);
            gets(s);
            w = strlen(s);
            if (w)
            {
                info = (char *)malloc((w + 1) * sizeof(char));
                strcpy(info, s);
                (*G).arcs[i][j], info = info;
            }
        }
    }  
    (*G).kind=DN;
    return OK;
}

//图的邻接矩阵存储结构的打印输出算法
void Display(MGraph G)
{
    int i, j;
    char s[7], s1[3];
    switch (G.kind)
    {
    case DG:
        strcpy(s, "有向图\0");
        strcpy(s1, "弧\0");
        break;
    case DN:
        strcpy(s, "有向网\0");
        strcpy(s1, "弧\0");
        break;
    case AG:
        strcpy(s, "无向图\0");
        strcpy(s1, "弧\0");
        break;
    case AN:
        strcpy(s, "无向网\0");
        strcpy(s1, "弧\0");
        break;
    }
    printf("%d个顶点%d条%s的%s\n", G.vexnum, G.arcnum, s);
    for (i = 0; i < G.vexnum; j++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%d\t", G.arcs[i][j].adj);
        printf("\n");
    }
    printf("G.arcs.info:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%s\t", G.arcs[i][j].info);
        prinrtf("\n");
    }
}
//邻接矩阵存储结构上的广度优先遍历算法
void BFSTraverse(MGraph G, Status (*Visit)(VertexType))
{
    int v, u, w;
    VertexType w1, ul;
    LinkQueue Q;
    Boolean visited[MAX_VERTEX_NUM];
    for (v = 0; v < G.vexnum; v++)
        visited[v] = ERROR;
    InitQueue(&Q);
    for (v = 0; v < G.vexnum; v++)
        if (!visited[v])
        {
            visited[v] = TRUE;
            Visit(G.vexs[w]);
            ;
            EnQueue(&Q, w);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &u);
                strcpy(ul, *GetVex(G, u));
                for (w = FirstAdjVex(G, ul); w >= 0;)
                {
                    if (!visited[w])
                    {
                        visited[w] = TRUE;
                        Visit(G.vexs[w]);
                        EnQueue(&Q, w);
                    }
                    w = NextAdjVex(G, ul, strcpy(w1, *GetVex(G, w)));
                }
            }
        }
    printf("\n");
}

//邻接矩阵存储结构上的深度优先遍历算法
void DFSTraverse(MGraph G, int v, Status (*Visit)(VertexType))
{
    Boolean Visited[MAX_VERTEX_NUM];
    int S[MAX_VERTEX_NUM] = {0};
    int top = -1;
    int j;
    Visit(G.vexs[v]);
    Visited[v] = 1;
    S[++top] = v;
    while (top != 1)
    {
        v = S[top];
        for (j = 0; j < G.vexnum; j++)
            if (G.arcs[v][j].adj == 1 && Visited[j] == 0)
            {
                Visit(G.vexs[j]);
                Visited[j] = 1;
                S[++top] = j;
                break;
            }
        if (j == G.vexnum)
            top--;
    }
}
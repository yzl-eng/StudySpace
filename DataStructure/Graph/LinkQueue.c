#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ERROR 0
#define OK 1

typedef int Elemtype;
typedef struct node
{
	Elemtype data;
	struct node *next;
}QueueNode;

typedef struct{
	QueueNode *front;
	QueueNode *rear;
}LinkQueue;
//队列初始化
int InitQueue(LinkQueue *Q)
{
	Q->front=(QueueNode *)malloc(sizeof(QueueNode));
	Q->front->next=NULL;
	Q->rear=Q->front;
	return OK;
 } 
//入队
int EnQueue(LinkQueue *Q,Elemtype e)
{
	QueueNode *p;
	p=(QueueNode *)malloc(sizeof(QueueNode));
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}
//出队
int DeQueue(LinkQueue *Q,Elemtype *e)
{
	QueueNode *p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return OK;

}
//清空链队
int ClearQueue(LinkQueue *Q)
{
	QueueNode *p,*t;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	Q->front->next=NULL;
	t=p->next;
	while(t!=Q->rear)
		{
			free(p);
			p=t;
			t=p->next;
		}
	Q->rear=Q->front;
}
//取链队列头元素
Elemtype GetHead(LinkQueue *Q)
{
	QueueNode *p;
	Elemtype e;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	e=p->data;
	return e;
}
//队列长度
Elemtype QueueLength(LinkQueue *Q)
{
	QueueNode *p;
	int i=0;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;	
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;	
 } 
//判断链队列是否为空
int QueueEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear)
		return ERROR;
	else
		return OK;
}
//打印队列元素
int PrintElem(LinkQueue *Q)
{
	QueueNode *p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	return OK;
 } 
//主菜单 
void menu()
 {	
 	printf("**************************************************************\n");
 	printf("**************************************************************\n");
 	printf("**********                                     ***************\n");
 	printf("*******                                             **********\n");
 	printf("                     主菜单\n");
 	printf("       -------------------------------------------\n");
 	printf("                    请选择操作\n");
 	printf("      [1]进队                                 [2]出队\n");
 	printf("      [3]清空                                 [4]队列长度\n");
	printf("      [5]取队头元素                           [0]退出 ");
	printf("\n请输入编号：\n");
	printf("\n");
 }

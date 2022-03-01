#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define QUEUE_INITSIZE 10
#define ERROR 0
#define OK 1
typedef int Elemtype;
typedef struct node_1{
	Elemtype *elem;
	int front,rear,tag;
	int QueueSize;
}SeqQueue;
//初始化队列 
int InitQueue(SeqQueue *Q)
{
	Q->elem=(Elemtype *)malloc(sizeof(Elemtype)*QUEUE_INITSIZE);
	if(!(Q->elem))
		return ERROR;
	Q->QueueSize=QUEUE_INITSIZE;
	Q->front=Q->rear=0;
	Q->tag=0;
	return OK;	
}
//入队 
int EnQueue(SeqQueue *Q,Elemtype e)
{
	if(Q->tag==1)
		return ERROR;	
	Q->elem[Q->rear]=e;
	if(Q->front==Q->rear&&Q->tag!=0)
		Q->tag=1;
	else
		Q->tag=2;	
	Q->rear=(Q->rear+1)%Q->QueueSize;
	return OK;
}
//出队 
int DeQueue(SeqQueue *Q,Elemtype *e)
{
	if(Q->tag==0)
		return ERROR;
	*e=Q->elem[Q->front];
	Q->front=(Q->front+1)%Q->QueueSize;
	if(Q->front==Q->rear)
	{
		Q->tag=0;
		return ERROR;
	}
	return OK;
}

//循环列表判空操作

int QueueEmpty(SeqQueue *Q)
{
	if(Q->tag==0)
		return ERROR;
	else
		return OK;
}

//求循环列表长度
int QueueLength(SeqQueue *Q)
{
		return (Q->rear-Q->front+Q->QueueSize)%Q->QueueSize;	
}

//循环队列判满操作
int IsFull(SeqQueue *Q)
{
	if(Q->tag==1)
		return 0;
	else
		return 1;
}
//清空队列
int ClearQueue(SeqQueue *Q)
{
	if(Q->tag==0)
		return OK;
	Q->front=Q->rear=0;
	Q->tag=0;
	return OK;
 } 
 
//取头元素
Elemtype GetHead(SeqQueue *Q)
{
	Elemtype e;
	if(Q->front==Q->rear)
		return ERROR;
	e=Q->elem[Q->front];
	return e;
 } 
//打印队列
void PrintQueueElem(SeqQueue *Q)
{
	int i;
	i=Q->front;
	if(i<Q->rear&&Q->tag==2)
	{
		while(i!=Q->rear)
		{
			printf("%d ",Q->elem[i]);
			i=(i+1)%Q->QueueSize;
		}
	}
	else
	{
		do{
			printf("%d ",Q->elem[i]);
			i=(i+1)%Q->QueueSize;
		}
			while(i!=Q->rear);
	}
//	{
//		while(i<Q->rear)
//		{
//			printf("%d ",Q->elem[i]);
//			i++;
//		}
//	}
//	else if(Q->tag==1)
//	{
//		for(i=Q->front;i<QUEUE_INITSIZE;i++)
//			printf("%d ",Q->elem[i]);
//		for(i=0;i<=Q->rear;i++)
//			printf("%d",Q->elem[i]);
//	}		
 } 
void QueueMenu()
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
 

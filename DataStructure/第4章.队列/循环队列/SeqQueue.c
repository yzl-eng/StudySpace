#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define QUEUE_INITSIZE 10
#define ERROR 0
#define OK 1
typedef int Elemtype;
typedef struct node{
	Elemtype *elem;
	int front,rear,tag;
	int QueueSize;
}SeqQueue;
//��ʼ������ 
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
//��� 
int EnQueue(SeqQueue *Q,Elemtype e)
{
	if((Q->rear+1)%Q->QueueSize==Q->front)
		return ERROR;	
	Q->elem[Q->rear]=e;
	Q->rear=(Q->rear+1)%Q->QueueSize;
	Q->tag=1;
	return OK;
}
//���� 
int DeQueue(SeqQueue *Q,Elemtype *e)
{
	if(Q->front==Q->rear)
		return ERROR;
	*e=Q->elem[Q->front];
	Q->front=(Q->front+1)%Q->QueueSize;
	return OK;
}

//ѭ���б��пղ���

int QueueEmpty(SeqQueue *Q)
{
	if(Q->front==Q->rear)
		return ERROR;
	else
	{
		Q->tag==0;
		return OK;
	}
}

//��ѭ���б���
int QueueLength(SeqQueue *Q)
{
		return (Q->rear-Q->front+Q->QueueSize)%Q->QueueSize;	
}

//ѭ��������������
int IsFull(SeqQueue *Q)
{
	if((Q->rear+1)%Q->QueueSize==Q->front&&Q->tag==0)
		return 0;
	else
		return 1;
}
//��ն���
int ClearQueue(SeqQueue *Q)
{
	if(Q->front=Q->rear)
		return OK;
	Q->front=Q->rear=0;
	return OK;
 } 
 
//ȡͷԪ��
Elemtype GetHead(SeqQueue *Q)
{
	Elemtype e;
	if(Q->front==Q->rear)
		return ERROR;
	e=Q->elem[Q->front];
	return e;
 } 
//��ӡ����
void PrintElem(SeqQueue *Q)
{
	int i;
	i=Q->front;
	if(Q->front<=Q->rear&&Q->tag==1)
	{
		while(i<Q->rear)
		{
			printf("%d ",Q->elem[i]);
			i++;
		}
	}
	else if(Q->tag==1)
	{
		for(i=Q->front;i<QUEUE_INITSIZE;i++)
			printf("%d ",Q->elem[i]);
		for(i=0;i<=Q->rear;i++)
			printf("%d",Q->elem[i]);
	}		
 } 
void menu()
 {	
 	printf("**************************************************************\n");
 	printf("**************************************************************\n");
 	printf("**********                                     ***************\n");
 	printf("*******                                             **********\n");
 	printf("                     ���˵�\n");
 	printf("       -------------------------------------------\n");
 	printf("                    ��ѡ�����\n");
 	printf("      [1]����                                 [2]����\n");
 	printf("      [3]���                                 [4]���г���\n");
	printf("      [5]ȡ��ͷԪ��                           [0]�˳� ");
	printf("\n�������ţ�\n");
	printf("\n");
 }
 

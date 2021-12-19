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
//���г�ʼ��
int InitQueue(LinkQueue *Q)
{
	Q->front=(QueueNode *)malloc(sizeof(QueueNode));
	Q->front->next=NULL;
	Q->rear=Q->front;
	return OK;
 } 
//���
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
//����
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
//�������
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
//ȡ������ͷԪ��
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
//���г���
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
//�ж��������Ƿ�Ϊ��
int QueueEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear)
		return ERROR;
	else
		return OK;
}
//��ӡ����Ԫ��
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
//���˵� 
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

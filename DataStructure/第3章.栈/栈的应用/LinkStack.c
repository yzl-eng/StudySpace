#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1

typedef int Elemtype;
typedef struct node{
	Elemtype data;
	struct node *next;
}LinkStack;

LinkStack *InitStack()
{
	LinkStack *S;
	S=(LinkStack *)malloc(sizeof(LinkStack));
	S->next=NULL;
	return S;
}


//��ջ��ջ 
int Push(LinkStack *S,Elemtype e)
{
	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	p->data=e;
	p->next=S->next;
	S->next=p;
	return OK;	
}

//��ջ��ջ
int Pop(LinkStack *S,Elemtype *e)
{
	LinkStack *p;
	if(S->next==NULL)
		return ERROR;
	p=S->next;
	*e=p->data;
	S->next=p->next;
	free(p);
	return OK;
} 


//ȡջ��Ԫ�� 
int GetTop(LinkStack *S,Elemtype *e)
{
	LinkStack *p;
	if(S->next==NULL)
		return ERROR;
	p=S->next;
	*e=S->data;
	return OK;
}

// ��ջ�п�
int StackEmpty(LinkStack *S)
{
	if(S->next==NULL)
		return ERROR;
	else
		return OK;	
 } 

//��ջ�����
int ClearStack(LinkStack *S)
{
	LinkStack *p,*top;
	top=S->next;
	S->next=NULL;
	while(top!=NULL)
	{
		p=top;
		top=top->next;
		free(p);
	}
	return OK;
 } 

//ջԪ�����
int PrintElem(LinkStack *S)
{
	LinkStack *p;
	p=S;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d ",p->data);
	}
	return OK;
 } 
 
//��ջ�����
int StackDepth(LinkStack *S)
{
	int cnt=0;
	LinkStack *p;
	p=S->next;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
 } 
//�˵����� 
void menu()
 {	
 	printf("**************************************************************\n");
 	printf("**************************************************************\n");
 	printf("**********                                     ***************\n");
 	printf("*******                                             **********\n");
 	printf("                     ���˵�\n");
 	printf("       -------------------------------------------\n");
 	printf("                    ��ѡ�����\n");
 	printf("      [1]��ջ                                 [2]��ջ\n");
 	printf("      [3]���                                 [4]���\n");
	printf("      [5]ȡջ��Ԫ��                           [0]�˳� ");
	printf("\n�������ţ�\n");
	printf("\n");
 } 



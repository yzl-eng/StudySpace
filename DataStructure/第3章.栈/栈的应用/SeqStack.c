#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define STACK_INITSIZE 10
#define STACK_INCREAMENT 5
typedef int Elemtype;
typedef struct stack{
	Elemtype *elem;
	int top;
	int stacksize;
}SeqStack;

int InitStack(SeqStack *s)
{
	s->elem=(Elemtype *)malloc(sizeof(Elemtype)*STACK_INITSIZE);
	if(!s->elem)
		return ERROR;
	s->top=0;
	s->stacksize=STACK_INITSIZE;
}

int push(SeqStack *s,Elemtype e)
{
	Elemtype *newbase,newsize;
	if(s->top<=s->stacksize-1)
	{
		newsize=(STACK_INITSIZE+STACK_INCREAMENT);
		newbase=(Elemtype *)realloc(s->elem,newsize*sizeof(Elemtype));
		if(!newbase)
			return ERROR;
		s->elem=newbase;
		s->stacksize=newsize;
	}
	s->elem[s->top]=e;
	s->top++;
}

int Pop(SeqStack *s,Elemtype *e)
{
	if(s->top<=0)
		return ERROR;
	*e=s->elem[s->top-1];
	s->top--;
	return OK;	
}

int GetTop(SeqStack *s,Elemtype *e)
{
	if(s->top<=0)
		return ERROR;
	*e=s->elem[s->top-1];
	return OK;
}

int ClearStack(SeqStack *s)
{	if(s->top<=0)
		return ERROR;
	s->top=0;
	return OK;
}

int StackDepth(SeqStack *s)
{
	if(s->top<=0)
		return ERROR;
	return s->top;	
 } 
 
 //��ӡջ��Ԫ��
 int PrintElem(SeqStack *s)
 {
 	int num;
 	num=0;
 	while(num<s->top)
 	{
 		printf("%d ",s->elem[num]);
 		num++;
	 }
	printf("\n");
		return OK;
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
 	printf("      [1]��ջ                                 [2]��ջ\n");
 	printf("      [3]���                                 [4]���\n");
	printf("      [5]ȡջ��Ԫ��                           [0]�˳� ");
	printf("\n�������ţ�\n");
	printf("\n");
 }
 
 

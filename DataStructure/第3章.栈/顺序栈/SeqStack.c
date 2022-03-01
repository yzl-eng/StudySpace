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
 
 //打印栈中元素
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
 	printf("                     主菜单\n");
 	printf("       -------------------------------------------\n");
 	printf("                    请选择操作\n");
 	printf("      [1]进栈                                 [2]出栈\n");
 	printf("      [3]清空                                 [4]深度\n");
	printf("      [5]取栈顶元素                           [0]退出 ");
	printf("\n请输入编号：\n");
	printf("\n");
 }
 
 

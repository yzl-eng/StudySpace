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


//链栈入栈 
int Push(LinkStack *S,Elemtype e)
{
	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	p->data=e;
	p->next=S->next;
	S->next=p;
	return OK;	
}

//链栈出栈
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


//取栈顶元素 
int GetTop(LinkStack *S,Elemtype *e)
{
	LinkStack *p;
	if(S->next==NULL)
		return ERROR;
	p=S->next;
	*e=S->data;
	return OK;
}

// 链栈判空
int StackEmpty(LinkStack *S)
{
	if(S->next==NULL)
		return ERROR;
	else
		return OK;	
 } 

//链栈的清空
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

//栈元素输出
int PrintStackElem(LinkStack *S)
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
 
 int PrintElem(LinkStack *S1,LinkStack *S2)
 {
 	if(StackEmpty(S1))
 	{
 		PrintStackElem(S1);
	 }
	 else
	{
	 	PrintStackElem(S2);
	}
 }
//求栈的深度
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
//菜单界面 
void menu()
 {	
 	printf("**************************************************************\n");
 	printf("**************************************************************\n");
 	printf("**********                                     ***************\n");
 	printf("*******                                             **********\n");
 	printf("                     主菜单\n");
 	printf("       -------------------------------------------\n");
 	printf("                    请选择操作\n");
 	printf("      [1]进队                                 [2]出对\n");
	printf("                                              [0]退出 ");
	printf("\n请输入编号：\n");
	printf("\n");
 } 

int EnQueue(LinkStack *S1, LinkStack  *S2, Elemtype  x) 
{
	int e;
	if(!StackEmpty(S1)&&StackEmpty(S2))
		while(StackEmpty(S2))
		{
			Pop(S2,&e);
			Push(S1,e);
		}
	Push(S1,x);
}

void DeQueue(LinkStack *S1, LinkStack  *S2,Elemtype *x)
{
	int e;
	if(!StackEmpty(S2))
		while(StackEmpty(S1))
		{
			Pop(S1,&e);
			Push(S2,e);
		}
	Pop(S2,x);
}

int QueueEmpty(LinkStack *S1, LinkStack  *S2)
{
	if(StackEmpty(S2)&&StackEmpty(S1))
		return ERROR;
	else
		return OK;	
}

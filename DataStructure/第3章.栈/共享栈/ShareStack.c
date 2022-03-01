#include<stdio.h>
typedef int Elemtype;
typedef struct
{
	Elemtype elem[M];
	int top1,top2;
}SharedStack;

int InitStack(ShareStack *S)
{
	S->top1=-1;
	S->top2=M;
	return OK;
}
// 进栈操作 
int Push(SharedStack *S,Elemtype e,int i)
{
	if(S->top1==S->top2)
		return ERROR;
	switch(i)
	{
		case 1:
			S->top1++;
			S->elem[S->top1]=e;
			break;
		case 2:
			S->top2--;
			S->elem[S->top2]=e;
			break;
		default:
			return ERROR;	
	}
	return OK;	
}
//出栈操作
int Pop(SharedStack *S,Elemtype *e,int i)
{
	switch(i)
	{
		case 1:
		if(S->top1==-1)
			return ERROR;
		*e=S->elem[S->top1];
			S->top1--;
			break;
		case 2:
		if(S->top2==M)
			return ERROR;
			*e=->elem[S->top2];
			S->top2++;
			break;
		default:
			return ERROR;	
	}
	return OK;	
}

//求栈的深度
int StackDepth(SharedStack *S,int i)
{
	switch(i)
	{
		case 1:
			return S->top1+1;
			break;
		case 2:
			return M-S->top2;
			break;
		default:
			return ERROR;	
	}
}
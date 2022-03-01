#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ERROR 0;
#define OK 1;

typedef int Elemtype;
typedef struct node
{
	Elemtype data;
	struct node *next;
}LinkList;

//单链表链表初始化 
LinkList *InitList()
{
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}


//单链表头插法 
LinkList *CreateList_nx(int n)
{
	int i;
	LinkList *head,*p;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	for ( i = 1; i <=n; i++)
	{
		p=(LinkList*)malloc(sizeof(LinkList));
		scanf("%d",&p->data);
		p->next=head->next;
		head->next=p;
	}

	return head;
}

//单链表尾插法 
LinkList *CreateList(int n)
{
	int i;
	LinkList *head,*p,*r;
	head=(LinkList *)malloc(sizeof(LinkList));
	r=head;
	for (i=1; i<=n; i++)
	{
		p=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d",&(p->data));
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return head;
}

//单链表链表长度 
int ListLength(LinkList *head)
{
	int cnt=0;
	LinkList *p;
	p=head->next;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

//单链表取链表元素 
int GetElem(LinkList *head,int i,Elemtype *e)
{
	int j;
	LinkList *p;
	p=head->next;
	j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL||j>i)
		return ERROR;
	*e=p->data;
	return OK;
}

//单链表元素定位
int LocateElem(LinkList *head,Elemtype e,int cnt)
{
	LinkList *p;
	while(p!=NULL&&p->data!=e)
	{
		p=p->next;
		cnt++;
	}
	if(p==NULL)
		return 0;
	else
		return cnt;	
 }
 
  
//单链表插入元素 
int InsertElem(LinkList *head,int i,Elemtype e)
{
	int j;
	LinkList *s,*p;
	if(i<1)
		return ERROR;
	j=0;
	p=head;
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
		return ERROR;
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

//单链表链表元素删除算法 
int DeleteElem(LinkList *head,int i,Elemtype *e)
{
	int cnt=0;
	LinkList *p,*q;
	p=head;
	if(i<1)
		return ERROR;
	while(p->next!=NULL&&cnt<i-1)
	{
		p=p->next;
		cnt++;
	}
	if(p->next==NULL)
		return ERROR;
	q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	return OK;
}

//单链表输出链表内容 
void PrintElem(LinkList *head)
{
	int i;
	LinkList *p;
	p=head;
	for(i=1;i<=ListLength(head);i++)
	{
		p=p->next;
		printf("%d ",p->data);
	}
	printf("\n");
}

//单链表上的倒置算法
int ConvertList(LinkList *head)
{
	LinkList *p,*s;
	p=head->next;
	head->next=NULL;
	while(p!=NULL)
	{
		s=p;
		p=p->next;
		s->next=head->next;
		head->next=s;
	}
	return OK;
 } 
 
 //单链表删除重复元素 
 void DeleteRepElem(LinkList *head)
 {
 	LinkList *p,*q,*r;
	for(r=head->next;r->next!=NULL;r=r->next)
	{
		for(p=r,q=p->next;q!=NULL;p=q,q=q->next)
		{
			while(q->data==r->data&&q->next!=NULL)
			{
				p->next=q->next;
				free(q);
				q=p->next;
			}
			if(q->data==r->data&&q->next==NULL)
			{
				p->next=NULL;
				free(q);
				break;
			}
		}
	}
 }

 //删除重复元素
//int DeleteRepElem(LinkList *head)
//{
//	LinkList *p,*r,*t;
//	for(p=head->next;p->next!=NULL;p=p->next)
//	{
//		for(t=p,r=p->next;r!=NULL;t=r,r=r->next)
//		{
//			while(p->data==r->data&&r->next!=NULL)
//			{
//				t->next=r->next;
//				free(r);
//                r=t->next;
//			}
//			if(p->data==r->data&&r->next==NULL)
//			{
//				t->next=NULL;
//				free(r);
//				break;
//			}			
//		}
//	}
//	return OK;	
// } 


//
//int DeleteRepElem(LinkList *head)
//{
//	Elemtype e;
//	LinkList *p,*r,*t;
//	for(p=head->next;p->next!=NULL;p=p->next)
//	{
//		for(r=p->next;r!=NULL;r=r->next)
//		{
//			DeleteElem(head,LocateElem(head,p->data),&e);
//		}
//	}
//	return OK;	
// } 

 
  //删除指定元素 
int DeleteSelElem(LinkList *head,Elemtype e)
 {
 	LinkList *q,*p;
 	Elemtype n;
 	int cnt=0;
 	q=head->next;
while(q!=NULL)
{
 		cnt++;
 		if(q->data==e)
		{
			q=q->next;
 			DeleteElem(head,cnt,&n);
			cnt--;
		}
		else	
			q=q->next;	
	}
	return OK;
 }
 
 //删除最小元素 
Elemtype DeleteMinElem(LinkList *head)
 {
 	LinkList *q,*p;
 	Elemtype e;
 	p=head->next;
 	for(q=p->next;q!=NULL;q=q->next)
 	{
 		if(p->data>q->data)
 			{
 				p=q;
			 }
 			
	 }
	 e=p->data;
	 DeleteSelElem(head,e);
	 return e;
 }
 



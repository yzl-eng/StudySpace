#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef struct node{
	Elemtype data;
	struct node *next,*before;
}DulLinkList;

//双链表初始化 
DulLinkList *InitList()
{
	DulLinkList *head;
	head=(DulLinkList *)malloc(sizeof(DulLinkList));
	head->next=NULL;
	head->before=NULL;
	return head;	
}

//双链表的创建
DulLinkList *CreateList(int n)
{
	int i;
	DulLinkList *head,*p,*r;
	head=(DulLinkList *)malloc(sizeof(DulLinkList));
	head->before=NULL;
	r=head;
	for(i=1;i<=n;i++)
	{
		p=(DulLinkList *)malloc(sizeof(DulLinkList));
		scanf("%d",&p->data);
		r->next=p;
		p->before=r;
		r=p;
	}
	r->next=NULL;
	return head;
 } 
 
 // 双链表插入算法
 int InsertElem(DulLinkList *head,int i,Elemtype e) 
 {
	int j;
	DulLinkList *s,*p;
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
	s=(DulLinkList *)malloc(sizeof(DulLinkList));
	s->data=e;
	s->next=p->next; 
	s->before=p;
	if(p->next!=NULL)
		p->next->before=s;
	p->next=s;
	return OK;			 	
 }
 
 //双链表的删除算法
int DeleteElem(DulLinkList *head,int i,Elemtype *e)
{
	int j;
	DulLinkList *p,*q;
	if(i<1)
		return ERROR;
	p=head;
	j=0;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next==NULL)
		return ERROR;
	q=p->next;
	*e=q->data;
	p->next=q->next;
	if(q->next!=NULL)
		q->next->before=p;
	free(q);
	return OK;			
 } 
 
 //双链表长度
 int ListLength(DulLinkList *head)
 {
 	int cnt=0;
 	DulLinkList *p;
 	p=head;
 	while(p->next!=NULL)
 	{
 		p=p->next;
 		cnt++;
	 }
	 return cnt;
  } 
  
 //双链表的输出
 void PrintElem(DulLinkList *head)
 {
 	int j=0;
 	DulLinkList *p;
 	p=head;
 	for(j=1;j<=ListLength(head);j++)
 	{
 		p=p->next;
 		printf("%d ",p->data);
 		
	}
 	
  } 

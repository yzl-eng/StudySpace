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

//�����������ʼ�� 
LinkList *InitList()
{
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}


//������ͷ�巨 
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

//������β�巨 
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

//������������ 
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

//������ȡ����Ԫ�� 
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

//������Ԫ�ض�λ
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
 
  
//���������Ԫ�� 
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

//����������Ԫ��ɾ���㷨 
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

//����������������� 
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

//�������ϵĵ����㷨
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
 
 //������ɾ���ظ�Ԫ�� 
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

 //ɾ���ظ�Ԫ��
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

 
  //ɾ��ָ��Ԫ�� 
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
 
 //ɾ����СԪ�� 
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
 



#include"DulLinkList.c"
int main(void)
{
	int n,i,e,flag,flag_2;
	flag_2=0;
	DulLinkList *head,*p,*q;
	head=InitList();
	printf("����Ҫ����Ľڵ���\n");
	scanf("%d",&n);
	head=CreateList(n);
	printf("����Ԫ��\n");
//	PrintElem(head);
	flag=ListLength(head)%2;
	p=head;
	q=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head;
	head->before=p;
	q=head->next;
	while(q!=head)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	p=head->next;
	q=head->before;
	while(p->data==q->data)
	{
		if(flag==1&&(p->next==q->before))
		{
			flag_2=1;
			break; 
		}
		if(flag==0&&p->next==q)
		{
			flag_2=1;
			break; 
		}
		p=p->next;
		q=q->before;
	}
	if(flag_2==1)
		printf("\n�Գ�\n");
	else
		printf("\n���Գ�\n");	
	return 0;
}

#include"LinkList.c"
int main(void)
{
	int n,m,e,a;
	m=1; 
	LinkList *head;
	head=InitList();
	printf("����Ҫ����Ľڵ������\n");
	scanf("%d",&n);
	printf("β�巨��������\n");
	head=CreateList(n);
	printf("�����\n");
	PrintElem(head);
	while(m!=-9)
	{
		printf("������Ҫɾ���Ľڵ�\n");
		scanf("%d",&m);
		GetElem(head,m,&a);
		if(DeleteElem(head,m,&e))
		{
			printf("ɾ���Ľڵ��Ԫ��Ϊ��%d\n",a);
			printf("ɾ�����\n");
			PrintElem(head);
		}
		else
			printf("��������\n");
		if(ListLength(head)==0)
		{
			printf("�ñ�Ϊ��\n");	
			break;
		}
			
	}
	printf("���н���");
	return 0;
}

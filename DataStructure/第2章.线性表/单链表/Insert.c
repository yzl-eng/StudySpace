#include"LinkList.c"
int main(void)
{
	int n,m,x;
	LinkList *head;
	head=InitList();
	printf("����Ҫ����Ľڵ������\n");
	scanf("%d",&n);
	printf("ͷ�巨����������\n");
	head=CreateList_nx(n);
	printf("�����\n");
	PrintElem(head);
	printf("������Ҫ�����λ��\n");
	scanf("%d",&m);
	printf("������Ҫ�������\n");
	scanf("%d",&x);
	if(!InsertElem(head,m,x))
		printf("ERROR:����λ�ò�����");
	else
	{	
		printf("�����\n");
		PrintElem(head);
	}
	return 0;
}

#include"LinkList.c"
int main(void)
{
	int n,m,e,a;
	LinkList *head;
	head=InitList();
	printf("����Ҫ����Ľڵ������\n");
	scanf("%d",&n);
	printf("β�巨��������\n");
	head=CreateList(n);
	printf("�����\n");
	PrintElem(head);
	printf("������Ҫɾ���Ľڵ�\n");
	scanf("%d",&m);
	GetElem(head,m,&e);
	if(DeleteElem(head,m,&e))
	{
		printf("ɾ���Ľڵ��Ԫ��Ϊ��%d\n",a);
		printf("ɾ�����\n");
		PrintElem(head);
	}
	else
		printf("��������");
	return 0;
}

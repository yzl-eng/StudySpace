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
	ConvertList(head);
	printf("���������\n");
	PrintElem(head);
	return 0;
}

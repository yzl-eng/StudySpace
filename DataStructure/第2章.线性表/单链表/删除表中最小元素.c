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
	DeleteMinElem(head);
	printf("ɾ����СԪ�غ�\n");
	PrintElem(head);
	return 0;
}

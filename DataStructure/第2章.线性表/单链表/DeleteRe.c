#include"LinkList.c"
int main(void)
{
	int n,m,e;
	LinkList *head;
	head=InitList();
	printf("����Ҫ����Ľڵ������\n");
	scanf("%d",&n);
	printf("β�巨��������\n");
	head=CreateList(n);
	printf("�����\n");
	PrintElem(head);
	DeleteRepElem(head);
	printf("ɾ���ظ�Ԫ�غ������\n");
	PrintElem(head);
	return 0;
}

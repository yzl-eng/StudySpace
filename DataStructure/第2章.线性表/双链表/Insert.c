#include"DulLinkList.c"
int main(void)
{
	int n,i,e;
	DulLinkList *head;
	head=InitList();
	printf("����Ҫ����Ľڵ���\n");
	scanf("%d",&n);
	head=CreateList(n);
	printf("����Ԫ��\n");
	PrintElem(head);
	printf("\n����Ҫ�����λ��\n");
	scanf("%d",&i);
	printf("����Ҫ�������\n");
	scanf("%d",&e);
	InsertElem(head,i,e);
	PrintElem(head);
	return 0;
}

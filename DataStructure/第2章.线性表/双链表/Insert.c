#include"DulLinkList.c"
int main(void)
{
	int n,i,e;
	DulLinkList *head;
	head=InitList();
	printf("输入要加入的节点数\n");
	scanf("%d",&n);
	head=CreateList(n);
	printf("表中元素\n");
	PrintElem(head);
	printf("\n输入要插入的位置\n");
	scanf("%d",&i);
	printf("输入要插入的数\n");
	scanf("%d",&e);
	InsertElem(head,i,e);
	PrintElem(head);
	return 0;
}

#include"LinkList.c"
int main(void)
{
	int n,m,x;
	LinkList *head;
	head=InitList();
	printf("输入要加入的节点个数：\n");
	scanf("%d",&n);
	printf("头插法倒叙序输入\n");
	head=CreateList_nx(n);
	printf("输出：\n");
	PrintElem(head);
	ConvertList(head);
	printf("倒叙输出：\n");
	PrintElem(head);
	return 0;
}

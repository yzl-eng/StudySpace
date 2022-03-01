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
	printf("请输入要插入的位置\n");
	scanf("%d",&m);
	printf("请输入要插入的数\n");
	scanf("%d",&x);
	if(!InsertElem(head,m,x))
		printf("ERROR:插入位置不存在");
	else
	{	
		printf("输出：\n");
		PrintElem(head);
	}
	return 0;
}

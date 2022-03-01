#include"LinkList.c"
int main(void)
{
	int n,m,e,a;
	LinkList *head;
	head=InitList();
	printf("输入要加入的节点个数：\n");
	scanf("%d",&n);
	printf("尾插法正序输入\n");
	head=CreateList(n);
	printf("输出：\n");
	PrintElem(head);
	printf("请输入要删除的节点\n");
	scanf("%d",&m);
	GetElem(head,m,&e);
	if(DeleteElem(head,m,&e))
	{
		printf("删除的节点的元素为：%d\n",a);
		printf("删除输出\n");
		PrintElem(head);
	}
	else
		printf("输入有误");
	return 0;
}

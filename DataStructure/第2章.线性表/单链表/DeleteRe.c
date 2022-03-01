#include"LinkList.c"
int main(void)
{
	int n,m,e;
	LinkList *head;
	head=InitList();
	printf("输入要加入的节点个数：\n");
	scanf("%d",&n);
	printf("尾插法正序输入\n");
	head=CreateList(n);
	printf("输出：\n");
	PrintElem(head);
	DeleteRepElem(head);
	printf("删除重复元素后输出：\n");
	PrintElem(head);
	return 0;
}

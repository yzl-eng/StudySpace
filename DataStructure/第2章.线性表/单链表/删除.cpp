#include"LinkList.c"
int main(void)
{
	int n,m,e,a;
	m=1; 
	LinkList *head;
	head=InitList();
	printf("输入要加入的节点个数：\n");
	scanf("%d",&n);
	printf("尾插法正序输入\n");
	head=CreateList(n);
	printf("输出：\n");
	PrintElem(head);
	while(m!=-9)
	{
		printf("请输入要删除的节点\n");
		scanf("%d",&m);
		GetElem(head,m,&a);
		if(DeleteElem(head,m,&e))
		{
			printf("删除的节点的元素为：%d\n",a);
			printf("删除输出\n");
			PrintElem(head);
		}
		else
			printf("输入有误\n");
		if(ListLength(head)==0)
		{
			printf("该表为空\n");	
			break;
		}
			
	}
	printf("运行结束");
	return 0;
}

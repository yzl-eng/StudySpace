#include"LinkList.c"
int main(void)
{
	int numb,n,m,e,a; 
	LinkList *head;
	head=InitList();
	printf("1.链表元素插入\n"); 
	printf("2.删除链表元素\n");
	printf("3.定位链表元素\n");
	printf("4.去链表元素\n");
	printf("5.打印链表元素\n");
	printf("0.结束程序");
	m=1; 
	scanf("%d", &numb);
	system("cls");
	switch(numb)
	{
		case 1:while()
		case 2:	while(m!=-9)
				{
					printf("请输入要删除的节点\n");
					scanf("%d",&m);
					GetElem(head,m,&a);
					if(DeleteElem(head,m,&e))
					{
						printf("删除的节点的元素为：%d\n",a);
						printf("删除输出\n");
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
				return;
		case 3:if(LocateElem(head,e))
				{
					printf("定位成功\n");
					printf("%d",LocateElem(head,e));
				}
				else
					printf("定位失败\n");
				system("pause");
				break;	
		case 4:	PrintElem(head);
				system("pause");
				break;
		default:printf("输入有误\n");
				system("pause");
				break;	
			
	}
	return 0; 
}

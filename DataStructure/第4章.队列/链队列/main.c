#include"LinkQueue.c"
int main(void)
{
	LinkQueue s;
	int select,e,n,i;
	InitQueue(&s);
	while(1)
	{
		menu();
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				printf("输入要加入元素个数\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&e);
					EnQueue(&s,e);
				} 
				printf("队中元素为\n");
				PrintElem(&s);
				system("pause");
				system("cls");
				break;
			case 2:
				DeQueue(&s,&e);
				printf("删除的元素为%d\n",e);
				system("pause");
				system("cls");
				break;
			case 3:
				if(QueueEmpty(&s))
				{
					ClearQueue(&s);
					printf("栈已清空\n");
				}
				printf("队列为空");
				system("pause");
				system("cls");
				break;
			case 4:
				printf("队列长度为%d\n",QueueLength(&s));
				system("pause");
				system("cls");
				break;
			case 5:
				if(QueueEmpty(&s))
					printf("队头元素为%d\n",GetHead(&s));
				printf("队列为空，请添加元素后再操作\n");	
				system("pause");
				system("cls");
				break;
			case 0:
				printf("程序结束");
				return; 
			default:
				printf("请输入正确的编号\n");
				system("pause");
				system("cls");
				break;			
		}
		
	}
	return 0;
}

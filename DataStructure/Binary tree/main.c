#include"Stack&Queue.c"
int main(void)
{
	LinkStack *S1,*S2;
	S1=InitStack();
	S2=InitStack();
	int select,e,n,i;
	
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
						EnQueue(S1,S2,e);
					} 
					printf("队中元素为\n");
					PrintElem(S1,S2);
					system("pause");
					system("cls");
					break;
				case 2:
					DeQueue(S1,S2,&e);
					printf("删除的元素为%d\n",e);
					system("pause");
					system("cls");
					break;
	//			case 3:
	//				ClearQueue(&s);
	//				printf("栈已清空\n");
	//				system("pause");
	//				system("cls");
	//				break;
	//			case 4:
	//				printf("队列长度为%d\n",QueueLength(&s));
	//				system("pause");
	//				system("cls");
	//				break;
	//			case 5:
	//				if(QueueEmpty(&s))
	//					printf("队头元素为%d\n",GetHead(&s));
	//				else
	//					printf("队列为空，请添加元素后再操作\n");	
	//				system("pause");
	//				system("cls");
	//				break;
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

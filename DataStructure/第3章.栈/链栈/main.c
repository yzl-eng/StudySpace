#include"LinkStack.c"
int main(void)
{
	LinkStack *s;
	int select,e,n,i;
	s=InitStack();
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
					Push(s,e);
				} 
				printf("栈中元素为\n");
				PrintElem(s);
				system("pause");
				system("cls");
				break;
			case 2:
				if(StackEmpty(s)==0)
				{
					printf("栈为空,请添加元素后再操作\n");
					system("pause");
					system("cls"); 
					break;
				}
				Pop(s,&e);
				printf("栈中元素为\n");
				PrintElem(s);
				printf("删除的元素为%d\n",e);
				system("pause");
				system("cls");
				break;
			case 3:
				ClearStack(s);
				printf("栈已清空\n");
				system("pause");
				system("cls");
				break;
			case 4:
				printf("栈深度为%d\n",StackDepth(s));
				system("pause");
				system("cls");
				break;
			case 5:
				printf("栈顶元素为%d\n",GetTop(s,&e));
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

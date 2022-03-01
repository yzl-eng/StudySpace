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
				printf("����Ҫ����Ԫ�ظ���\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&e);
					Push(s,e);
				} 
				printf("ջ��Ԫ��Ϊ\n");
				PrintElem(s);
				system("pause");
				system("cls");
				break;
			case 2:
				if(StackEmpty(s)==0)
				{
					printf("ջΪ��,�����Ԫ�غ��ٲ���\n");
					system("pause");
					system("cls"); 
					break;
				}
				Pop(s,&e);
				printf("ջ��Ԫ��Ϊ\n");
				PrintElem(s);
				printf("ɾ����Ԫ��Ϊ%d\n",e);
				system("pause");
				system("cls");
				break;
			case 3:
				ClearStack(s);
				printf("ջ�����\n");
				system("pause");
				system("cls");
				break;
			case 4:
				printf("ջ���Ϊ%d\n",StackDepth(s));
				system("pause");
				system("cls");
				break;
			case 5:
				printf("ջ��Ԫ��Ϊ%d\n",GetTop(s,&e));
				system("pause");
				system("cls");
				break;
			case 0:
				printf("�������");
				return; 
			default:
				printf("��������ȷ�ı��\n");
				system("pause");
				system("cls");
				break;			
		}
		
	}
	return 0;
}

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
				printf("����Ҫ����Ԫ�ظ���\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&e);
					EnQueue(&s,e);
				} 
				printf("����Ԫ��Ϊ\n");
				PrintElem(&s);
				system("pause");
				system("cls");
				break;
			case 2:
				DeQueue(&s,&e);
				printf("ɾ����Ԫ��Ϊ%d\n",e);
				system("pause");
				system("cls");
				break;
			case 3:
				if(QueueEmpty(&s))
				{
					ClearQueue(&s);
					printf("ջ�����\n");
				}
				printf("����Ϊ��");
				system("pause");
				system("cls");
				break;
			case 4:
				printf("���г���Ϊ%d\n",QueueLength(&s));
				system("pause");
				system("cls");
				break;
			case 5:
				if(QueueEmpty(&s))
					printf("��ͷԪ��Ϊ%d\n",GetHead(&s));
				printf("����Ϊ�գ������Ԫ�غ��ٲ���\n");	
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

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
					printf("����Ҫ����Ԫ�ظ���\n");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						scanf("%d",&e);
						EnQueue(S1,S2,e);
					} 
					printf("����Ԫ��Ϊ\n");
					PrintElem(S1,S2);
					system("pause");
					system("cls");
					break;
				case 2:
					DeQueue(S1,S2,&e);
					printf("ɾ����Ԫ��Ϊ%d\n",e);
					system("pause");
					system("cls");
					break;
	//			case 3:
	//				ClearQueue(&s);
	//				printf("ջ�����\n");
	//				system("pause");
	//				system("cls");
	//				break;
	//			case 4:
	//				printf("���г���Ϊ%d\n",QueueLength(&s));
	//				system("pause");
	//				system("cls");
	//				break;
	//			case 5:
	//				if(QueueEmpty(&s))
	//					printf("��ͷԪ��Ϊ%d\n",GetHead(&s));
	//				else
	//					printf("����Ϊ�գ������Ԫ�غ��ٲ���\n");	
	//				system("pause");
	//				system("cls");
	//				break;
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

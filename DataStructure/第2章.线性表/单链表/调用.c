#include"LinkList.c"
int main(void)
{
	int numb,n,m,e,a; 
	LinkList *head;
	head=InitList();
	printf("1.����Ԫ�ز���\n"); 
	printf("2.ɾ������Ԫ��\n");
	printf("3.��λ����Ԫ��\n");
	printf("4.ȥ����Ԫ��\n");
	printf("5.��ӡ����Ԫ��\n");
	printf("0.��������");
	m=1; 
	scanf("%d", &numb);
	system("cls");
	switch(numb)
	{
		case 1:while()
		case 2:	while(m!=-9)
				{
					printf("������Ҫɾ���Ľڵ�\n");
					scanf("%d",&m);
					GetElem(head,m,&a);
					if(DeleteElem(head,m,&e))
					{
						printf("ɾ���Ľڵ��Ԫ��Ϊ��%d\n",a);
						printf("ɾ�����\n");
					}
					else
						printf("��������\n");
					if(ListLength(head)==0)
					{
						printf("�ñ�Ϊ��\n");	
						break;
					}
						
				}
				printf("���н���");
				return;
		case 3:if(LocateElem(head,e))
				{
					printf("��λ�ɹ�\n");
					printf("%d",LocateElem(head,e));
				}
				else
					printf("��λʧ��\n");
				system("pause");
				break;	
		case 4:	PrintElem(head);
				system("pause");
				break;
		default:printf("��������\n");
				system("pause");
				break;	
			
	}
	return 0; 
}

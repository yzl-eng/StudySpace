#include"LinkStack.c"
int main(void)
{
	int i,n,m,e,a,b,flag=0,t;
	LinkStack *S,*p;
	S=InitStack();
	p=InitStack();
	printf("����Ҫ�����Ԫ�ظ���\n");
	scanf("%d",&m);
	printf("����Ҫ�����Ԫ��:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		Push(S,n);
	}
	printf("\n");
	PrintElem(S);
	for(i=1;i<=m/2;i++)
	{
		Pop(S,&e);
		Push(p,e);
	}
	if(m%2==1)
	{
		Pop(S,&e);
	}
	printf("\n");
	PrintElem(S);
	printf("\n");
	PrintElem(p);
	i=1;
	t=StackDepth(S);
	while(i!=t)
	{
		Pop(S,&a);
		Pop(p,&b);
		if(a!=b)
		{
			printf("���Գ�\n");
			flag=1;
			break; 
		}
		i++;
	}
	if(flag==0)
		printf("\n�Գ�");	
	return 0;
}

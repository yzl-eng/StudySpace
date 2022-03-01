#include"LinkStack.c"
int main(void)
{
	int i,n,m,e,a,b,flag=0,t;
	LinkStack *S,*p;
	S=InitStack();
	p=InitStack();
	printf("输入要加入的元素个数\n");
	scanf("%d",&m);
	printf("输入要加入的元素:\n");
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
			printf("不对称\n");
			flag=1;
			break; 
		}
		i++;
	}
	if(flag==0)
		printf("\n对称");	
	return 0;
}

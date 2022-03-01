#include"LinkStack.c"
int main(void)
{
	LinkStack p;
	InitStack(&p);
	int m,n,s;
	m=1;
	printf("请输入要转化的十进制数：\n");
	scanf("%d",&m);
	printf("转换的进制为：\n");
	scanf("%d",&n);
	while(m!=0)
	{
		s=m%n;
		Push(&p,s);
		m=m/n;
	 } 
	printf("转化为%d进制值为\n",n); 
	PrintElem(&p);
	return 0;
 } 

#include"LinkStack.c"
int main(void)
{
	LinkStack p;
	InitStack(&p);
	int m,n,s;
	m=1;
	printf("������Ҫת����ʮ��������\n");
	scanf("%d",&m);
	printf("ת���Ľ���Ϊ��\n");
	scanf("%d",&n);
	while(m!=0)
	{
		s=m%n;
		Push(&p,s);
		m=m/n;
	 } 
	printf("ת��Ϊ%d����ֵΪ\n",n); 
	PrintElem(&p);
	return 0;
 } 

#include"SeqList.c"
int main(void)
{
	int i,x;
	Elemtype date[N]={3,5,8,9,10};
    struct seqlist La;
	    InitList(&La);
	for(i=0;i<N;i++)
		InsertElem(&La,i+1,date[i]);
	printf("����ǰ\n");
	PrintElem(La);
	printf("����Ҫ�������\n");
	scanf("%d",&x);
	InsertElem_123(&La,x);
	printf("\n\n�����\n");
	PrintElem(La);
	printf("\nʱ�临�Ӷ�λO(n)");
	return 0;	
}

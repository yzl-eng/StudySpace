#include"SeqList.c"
int main(void)
{
	int i,x;
	Elemtype date[N]={3,5,8,9,10};
    struct seqlist La;
	    InitList(&La);
	for(i=0;i<N;i++)
		InsertElem(&La,i+1,date[i]);
	printf("插入前\n");
	PrintElem(La);
	printf("输入要插入的数\n");
	scanf("%d",&x);
	InsertElem_123(&La,x);
	printf("\n\n插入后\n");
	PrintElem(La);
	printf("\n时间复杂度位O(n)");
	return 0;	
}

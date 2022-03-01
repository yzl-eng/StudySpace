#include"SeqList.c"
int main(void)
{
	int i,n,m;
	srand((unsigned)time(NULL));
	Elemtype date[N];
    struct seqlist L1;
	    InitList(&L1);
	printf("插入算法\n\n");    
	for(i=0;i<N;i++)
	{
		date[i]=rand();
		InsertElem(&L1,i+1,date[i]);
	}
	PrintElem(L1);
	printf("要插入的数\n");
	scanf("%d",&m);
	printf("要插入的位\n");
	scanf("%d",&n);
	InsertElem(&L1,n,m);
	InsertSort(&L1);
	PrintElem(L1);
	return 0;	
}

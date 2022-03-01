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
//	printf("要插入的数\n");
//	scanf("%d",&m);
//	printf("要插入的位\n");
//	scanf("%d",&n);
//	InsertElem(&L1,n,m);

//
	printf("排序后\n"); 
	printf("排序\n");
	InsertSort(&L1);
	printf("选择排序\n");
	SelectSort(&L1); 
	BinSort(&L1);
	printf("冒泡排序\n");
	BubbleSort(&L1);
	printf("快速排序\n");
	QuickSort(&L1,0,L1.length-1);
	printf("希尔排序\n");
	ShellSort(&L1);
	PrintElem(L1);
	return 0;	
}

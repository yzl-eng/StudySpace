#include"SeqList.c"
int main(void)
{
	int i,n,m;
	srand((unsigned)time(NULL));
	Elemtype date[N];
    struct seqlist L1;
	    InitList(&L1);
	printf("�����㷨\n\n");    
	for(i=0;i<N;i++)
	{
		date[i]=rand();
		InsertElem(&L1,i+1,date[i]);
	}
	PrintElem(L1);
//	printf("Ҫ�������\n");
//	scanf("%d",&m);
//	printf("Ҫ�����λ\n");
//	scanf("%d",&n);
//	InsertElem(&L1,n,m);

//
	printf("�����\n"); 
	printf("����\n");
	InsertSort(&L1);
	printf("ѡ������\n");
	SelectSort(&L1); 
	BinSort(&L1);
	printf("ð������\n");
	BubbleSort(&L1);
	printf("��������\n");
	QuickSort(&L1,0,L1.length-1);
	printf("ϣ������\n");
	ShellSort(&L1);
	PrintElem(L1);
	return 0;	
}

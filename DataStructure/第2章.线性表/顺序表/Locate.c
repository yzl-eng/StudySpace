#include"SeqList.c"
int main(void)
{
	int i,Locate,*e,m;
	Elemtype date[N]={1,2,3,4,5};
    struct seqlist L1;
	    InitList(&L1);
	for(i=0;i<N;i++)
		InsertElem(&L1,i+1,date[i]);
	printf("定位算法\n\n");   	
	PrintElem(L1);
	printf("要定位的数\n");
	scanf("%d",&m);
	Locate=LocateElem(L1,m);
	printf("在第%d位",Locate);
	return 0;	
}

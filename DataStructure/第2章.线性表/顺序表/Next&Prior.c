#include"SeqList.c"
int main(void)
{
	int i,Locate,Next,m;
	Elemtype *e1,*e2;
	Next=0;
	Elemtype date[N]={1,2,3,4,5};
    struct seqlist L1;
	    InitList(&L1);
	for(i=0;i<N;i++)
		InsertElem(&L1,i+1,date[i]);
	PrintElem(L1);
	scanf("%d",&m);
	PriorElem(L1,m,e1);
	NextElem(L1,m,e2);
//	printf("前驱元素为%d\n",*e1);
//	printf("后继元素为%d",*e2);
	return 0;	
}

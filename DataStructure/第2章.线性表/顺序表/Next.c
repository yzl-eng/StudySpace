#include"SeqList.c"
int main(void)
{
	int i,Locate,Next,m;
	Elemtype *e1=0,*e2=0;
	Next=0;
	Elemtype date[N]={1,2,3,4,5};
    struct seqlist L1;
	    InitList(&L1);
	for(i=0;i<N;i++)
		InsertElem(&L1,i+1,date[i]);
	PrintElem(L1);
	scanf("%d",&m);
	NextElem(L1,m,e1);
	return 0;	
}

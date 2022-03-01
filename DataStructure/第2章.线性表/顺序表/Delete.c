#include"SeqList.c"
void PrintElem(struct seqlist L);
int main(void)
{
	int i,*e,n,m;
	Elemtype date[N]={3,2,4,6,5};
    struct seqlist L1;
	    InitList(&L1);
	printf("删除算法\n\n");     
	for(i=0;i<N;i++)
		InsertElem(&L1,i+1,date[i]);
	PrintElem(L1);
	printf("要删除的数\n");
	scanf("%d",&m);
	DeleteElem(&L1,m,&e);
	PrintElem(L1);
	return 0;	
}

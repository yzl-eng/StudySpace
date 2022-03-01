#include"SeqList.c"
int main(void)
{
	int i,*e;
	Elemtype date[N]={1,2,3,4,5};
	Elemtype date2[N]={3,5,8,9,10};
    struct seqlist La,Lb,Lc;
	    InitList(&La);
	    InitList(&Lb);
	    InitList(&Lc);
	for(i=0;i<N;i++)
		InsertElem(&La,i+1,date[i]);
	for(i=0;i<N;i++)
		InsertElem(&Lb,i+1,date2[i]);
		printf("合并前\n");
	PrintElem(La);
	PrintElem(Lb);	
	SymmetricDiference(&La,Lb);
	printf("\n\n合并后\n");
	PrintElem(La);
	return 0;	
}

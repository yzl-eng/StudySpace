#include"SeqList.c"
#define M 10
int main(void)
{
	int i;
	Elemtype date[M]={1,2,3,4,5,6,7,8,9,10};
	struct seqlist L;
	InitList(&L);
	for(i=0;i<M;i++)
	{
		InsertElem(&L,i+1,date[i]);
	} 
	PrintElem(L); 
	ReverseList(&L);
	PrintElem(L); 
	return 0;
}

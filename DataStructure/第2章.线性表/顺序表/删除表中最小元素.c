#include"SeqList.c"
int main(void)
{
	int i,n,m,t,e;
	t=0;
	//srand((unsigned)time(NULL));
	Elemtype date[N];
    struct seqlist L1;
	    InitList(&L1);    
	//for(i=0;i<N;i++)
	//{
		//date[i]=rand();
		InsertElem(&L1,i+1,date[i]);
	//}
	PrintElem(L1);
	if(ListLenth(L1)==0)
		printf("ERROR");
		return;
	for(i=1;i<ListLenth(L1);i++)
		{
			if(L1.elem[t]>L1.elem[i])
				t=i;
		}
	DeleteElem(&L1,t+1,&e);
	InsertElem(&L1,t+1,L1.elem[ListLenth(L1)]);
	DeleteElem(&L1,ListLenth(L1),&e);
	PrintElem(L1);	
	return 0;
}

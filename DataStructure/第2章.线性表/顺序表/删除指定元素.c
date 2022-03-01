#include"SeqList.c"
int main(void)
{
	int i,n,m,e,flag;
	flag=1;
	Elemtype date[N]={3,4,4,3,2};
    struct seqlist L2;
	    InitList(&L2);    
	for(i=0;i<N;i++)
	{
		InsertElem(&L2,i+1,date[i]);
	}
	PrintElem(L2);
	printf("要删除的数为:\n");
	scanf("%d",&n);
	/*while(flag==1)
	{
		flag=0;
		for(i=0;i<ListLenth(L2);i++)
			{	
				if(n==L2.elem[i])
				{
					DeleteElem(&L2,i+1,&e);
					i=1;
					flag=1;
				}
				
			}
	}*/	
	for(i=0;i<ListLenth(L2);i++)
			{	
				if(n==L2.elem[i])
				{
					DeleteElem(&L2,i+1,&e);
					i=i-1;
				}
				
			}
	PrintElem(L2);	
	return 0;
}

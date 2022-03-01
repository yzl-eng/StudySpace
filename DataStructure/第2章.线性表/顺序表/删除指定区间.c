#include"SeqList.c"
#define M 10
int main(void)
{
	int i,n,m,e;
	Elemtype date[M]={1,2,3,4,5,6,7,6,8,9,10};
    struct seqlist L1;
	    InitList(&L1);    
	for(i=0;i<M;i++)
	{
		InsertElem(&L1,i+1,date[i]);
	}
	PrintElem(L1);
	printf("设置删除下限：");
	scanf("%d",&n);
	printf("\n设置删除上限:");
	scanf("%d",&m);
	printf("\n");
	if(n>m&&ListLenth(L1)==0)
		printf("ERROR\n");	
	else
	{
		for(i=0;i<ListLenth(L1);i++)
		{
			if(L1.elem[i]>=n&&L1.elem[i]<=m)
			{
			DeleteElem(&L1,i+1,&e);
			i=i-1;
			}
		}
	PrintElem(L1);
	}
		
	return 0;
}

#include"SeqList.c"
int main(void)
{
	int i,Locate,*e,m;
	Elemtype date[N]={1,2,3,4,5};
    struct seqlist L1;
	    InitList(&L1);
	for(i=0;i<N;i++)
		InsertElem(&L1,i+1,date[i]);
	printf("��λ�㷨\n\n");   	
	PrintElem(L1);
	printf("Ҫ��λ����\n");
	scanf("%d",&m);
	Locate=LocateElem(L1,m);
	printf("�ڵ�%dλ",Locate);
	return 0;	
}

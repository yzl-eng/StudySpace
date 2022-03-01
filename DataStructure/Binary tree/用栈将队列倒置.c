#include"LinkStack.c"
#include"SeqQueue.c"
int main(void)
{
	LinkStack *S;
	SeqQueue Q;
	int n,i,e,x,m;
	S=InitStack();
	InitQueue(&Q);
	printf("���������Ԫ�ظ���:(���Ϊ10)\n");
	scanf("%d",&n);
	printf("Ԫ��Ϊ\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		EnQueue(&Q,e);
	}
	printf("����ǰ\n");
	PrintQueueElem(&Q);
	while(QueueEmpty(&Q))
	{
		DeQueue(&Q,&x);
		Push(S,x);
	}
	//printf("\n%d\n",StackDepth(S));
	//PrintElem(S);
	//for(i=0;i<m;i++)
	while(StackEmpty(S))
	{
		Pop(S,&x);
		EnQueue(&Q,x);
	}
	printf("\n���ú�\n");
	PrintQueueElem(&Q);
	//printf("\n%d",QueueLength(&Q));
	return 0; 
}

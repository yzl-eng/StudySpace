#include"LinkStack.c"
#include"SeqQueue.c"
int main(void)
{
	LinkStack *S;
	SeqQueue Q;
	int n,i,e,x,m;
	S=InitStack();
	InitQueue(&Q);
	printf("请输入入队元素个数:(最大为10)\n");
	scanf("%d",&n);
	printf("元素为\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		EnQueue(&Q,e);
	}
	printf("倒置前\n");
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
	printf("\n倒置后\n");
	PrintQueueElem(&Q);
	//printf("\n%d",QueueLength(&Q));
	return 0; 
}

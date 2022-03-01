#include"LinkStack.c"
#define M 6
#define N 10


int main(void)
{
	datatype dir;
	int i,t,x,y,d;
	LinkStack S;
	InitStack(&S);
	dir.x=1;dir.y=1;;dir.d=0;
	item move[4];
//增量数组
//上 
move[0].x=-1;
move[0].y=0;
//下 
move[1].x=1;
move[1].y=0;
//左 
move[2].x=0;
move[2].y=-1;
//右 
move[3].x=0;
move[3].y=1;
//move[4].x=0;
//move[4].y=0;
//
//move[5].x=0;
//move[5].y=0;
//
//move[6].x=0;
//move[6].y=0;
//
//move[7].x=0;
//move[7].y=0;
	//初始化迷宫 
	int maze[M+2][N+2]={0};
	for(i=0,t=1;i<N+1;i++)
		maze[t][i]=1;
	for(i=N,t=1;t<M+1;t++)
		maze[t][i]=1;
	maze[M][N+1]=1;
	//输出迷宫		
	for(i=0;i<M+2;i++)
	{
		for(t=0;t<N+2;t++)
		{
			printf("%d ",maze[i][t]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	Push(&S,dir);
	while(StackEmpty(&S))
	{
		Pop(&S,&dir);
		x=dir.x;y=dir.y;d=dir.d+1;
		while(d<4)
		{
			i=move[d].x;
			t=move[d].y;
			if(maze[i][t]==0)
			{
				dir.x=x;dir.y=y;dir.d=d;
				Push(&S,dir);
				x=i;y=t;
				maze[x][y]=-1;
				if(x==M&&y==N)
					return 1;
				else
					d=0;	
			}
			else 
				d++;
		}
	}
	PrintElem(&S);	
	return 0;
}

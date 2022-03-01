#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

#define LISTINISIZE 20
#define LISTINCREAMENT 5
#define ERROR 0
#define OK 1
#define N 5 

typedef int Elemtype;
struct seqlist
 {
	Elemtype *elem;
	int length;
	int listsize;
};

//��ʼ��˳��� 
int InitList(struct seqlist *L)
{
	L->elem=(Elemtype *)malloc(sizeof(Elemtype)*LISTINISIZE);
	if(!L->elem)
			return ERROR;
	L->length=0;
	L->listsize=LISTINISIZE;
	return OK;	
}

//˳�������㷨 
int InsertElem(struct seqlist *L,int i,Elemtype e)
{
	int j,newsize;
	Elemtype *newbase;
	if(i<1||i>L->length+1)
		return ERROR;
	if (L->length>=L->listsize)
	{
		newsize=(L->listsize+LISTINCREAMENT)*sizeof(Elemtype);
		newbase=(Elemtype *)realloc(L->elem,newsize);
		if (!(newbase))
			return ERROR;
		L->elem=newbase;
		L->listsize+=LISTINCREAMENT;
	}
	for (j=L->length;j>=i-1;j--)
		L->elem[j+1]=L->elem[j];
	L->elem[i-1]=e;
	L->length++;
	return OK;
}

//˳�����������㷨 
int InsertElem_123(struct seqlist *L,int x)
{
	int i=0,j,newsize;
	Elemtype *newbase;
	if(x>=L->elem[L->length-1])
		InsertElem(L,L->length+1,x);
	else
	{	
		while(i<L->length)
		{
			if(L->elem[i]>=x&&L->elem[i+1]>=x)
			{
				InsertElem(L,i+1,x);
				break;
			}
			i++;		
		}
	return OK;
	}
}


//˳���ɾ���㷨 
int DeleteElem(struct seqlist *L,int i,Elemtype *e)
{
	int j;
	if((i<=0)||i>L->length)
		return ERROR;
	*e=L->elem[i-1];
	for(j=i;j<=L->length-1;j++)
		L->elem[j-1]=L->elem[j];
	L->length--;
	return OK;
}

//˳���λ�㷨 
int LocateElem(struct seqlist L,Elemtype e)
{
	int i;
	for(i=0;i<=L.length-1;i++)
		if(L.elem[i]==e)
			return i+1;
	return ERROR;	
}

//˳�������ȡԪ�ز��� 
int GetElem(struct seqlist L,int i,Elemtype *e)
{
	if(i<1||i>L.length)
		return ERROR;
	*e=L.elem[i-1];
	return OK;
}

//˳�������ǰ��Ԫ�ز��� 
int PriorElem(struct seqlist L,Elemtype e,Elemtype *pre_e)
{
	int i=0;
	for(i=L.length-1;i>=1;i--)
	{
		if(e==L.elem[i])
		{
			printf("ǰ��Ԫ��Ϊ%d\n",L.elem[i-1]);
			//*pre_e=L.elem[i-1];
			return OK;
		}
	}
	return ERROR;
}

//˳���������Ԫ�ز��� 
int NextElem(struct seqlist L,Elemtype e,Elemtype *next_e)
{
	int i,n;
	for(i=L.length-1;i>=1;i--)
		{
			if(e==L.elem[i])
				{
					printf("���Ԫ��Ϊ%d\n",L.elem[i+1]);
					//*next_e=L.elem[i+1];
					return OK;
				}		
		}
		return ERROR;
}

//��ӡ˳�����Ϣ���� 
void PrintElem(struct seqlist L)
{
	int i;
	printf("��Ĵ洢�ռ�Ĵ�СΪ��%d\n",L.listsize);
	printf("���й���Ԫ��%d��������Ԫ���ǣ�\n", L.length);
	for(i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}


//����� 
int ListLenth(struct seqlist L)
{
		return L.length;	
}

//��ɼ���A=��A-B��U��B-A�������㷨
int SymmetricDiference(struct seqlist *La,struct seqlist Lb)
{
	int i,j,pos;
	Elemtype e,x;
	for(i=1;i<=ListLenth(Lb);i++)
	{
		GetElem(Lb,i,&e);
		pos=LocateElem(*La,e);
		if(pos==0)
			InsertElem(La,ListLenth(*La)+1,e);
		else
			DeleteElem(La,pos,&x);

	}
}

//���������ϳ�һ���µ�������㷨
void MergeList(struct seqlist *Lc,struct seqlist La,struct seqlist Lb)
{
	int i,j,lena,lenb;
	Elemtype e1,e2;
	InitList(Lc);
	lena=ListLenth(La);
	lenb=ListLenth(Lb);
	i=1;j=1;
	while(i<=lena&&j<=lenb)
	{
		GetElem(La,i,&e1);
		GetElem(Lb,j,&e2);
		if(e1<e2)
		{
			InsertElem(Lc,ListLenth(*Lc)+1,e1);
			i++;
		}
		else
		{
			InsertElem(Lc,ListLenth(*Lc)+1,e2);
			j++;
		}
	}
		while(i<=lena)
		{
			GetElem(La,i,&e1);
			i++;
			InsertElem(Lc,ListLenth(*Lc)+1,e1);
		}
		while(j<=lenb)
		{
			GetElem(Lb,j,&e2);
			j++;
			InsertElem(Lc,ListLenth(*Lc)+1,e2);
		}
}

//˳���Ԫ������ 
int ReverseList(struct seqlist *L)
{
	Elemtype box;
	int i=0;
	if(ListLenth(*L)==0)
		return ERROR;
	for(i=0;i<=(L->length)/2;i++)
	{
		box=L->elem[i];
		L->elem[i]=L->elem[L->length-i-1];
		L->elem[L->length-i-1]=box;
		}
	return OK;			 
}
//int ReverseList(struct seqlist L)
//{
//	Elemtype box;
//	int i=0;
//	if(ListLenth(L)==0)
//		return ERROR;
//	for(i=0;i<=(L.length)/2;i++)
//	{
//		box=L.elem[i];
//		L.elem[i]=L.elem[L.length-i-1];
//		L.elem[L.length-i-1]=box;
//		}
//	return OK;			 
//}
//ֱ�Ӳ�������
int InsertSort(struct seqlist *L)
{
	int i,j,temp;
	for(i=1;i<L->length;i++)
	{
		if(L->elem[i]<L->elem[i-1])
		{
			temp=L->elem[i];
			for(j=i-1;L->elem[j]>temp&&j>=0;j--)
				L->elem[j+1]=L->elem[j];
			L->elem[j+1]=temp;	
		}
	}
	return OK;
 } 
 
 //�۰��������
 void BinSort(struct seqlist *L)
 {
 		int i,j,low,high,mid,temp;
 		for(i=1;i<=L->length-1;i++)
 		{
 			if(L->elem[i]<L->elem[i-1])
 			{
 				temp=L->elem[i];
 				low=0;high=i-1;
 				while(low<=high)
 				{
 					mid=(low+high)/2;
 					if(L->elem[mid]>temp)
 						high=mid-1;
 					else
 						low=mid+1;
 				}
 				for(j=i-1;j>=high+1;j--)
 					L->elem[j+1]=L->elem[j];
 				L->elem[high+1]=temp;
 			}
		 }
 		
 }

 //ϣ������
 void ShellSort(struct seqlist *L)
 {
 	int i,j,d,temp;
 	for(d=L->length/2;d>=1;d=d/2)
 	{
 		for(i=d+1;i<L->length;i++)
 			if(L->elem[i]<L->elem[i-d])
	 		{
 				temp=L->elem[i];
 				for(j=i-d;j>0&&L->elem[j]>temp;j=j-d)
 					L->elem[j+d]=L->elem[j];
 				L->elem[j+d]=temp;	
			 }
	 }
 } 
 
 //ѡ������
 void SelectSort(struct seqlist *L)
 {
 	int i,j,m;
 	for(i=0;i<L->length-1;i++)
 	{
 		for(j=i+1;j<L->length;j++)
 		{
 			if(L->elem[i]>L->elem[j])
 			{
 				m=L->elem[i];
 				L->elem[i]=L->elem[j];
 				L->elem[j]=m;
			 }
		 }
	 }
  } 
  
//ð������
void BubbleSort(struct seqlist *L)
{
	int i,j,temp,flag=1,m;
	for(i=0;flag==1&&i<L->length;i++)
 	{
 		flag=0;
 		for(j=i;j<L->length-1;j++)
 		{
 			if(L->elem[j]>L->elem[j+1])
 			{
 				m=L->elem[j];
 				L->elem[j]=L->elem[j+1];
 				L->elem[j+1]=m;
 				flag=1;
			 }
		 }
	 }
 }
 
 
 //��������
 void QuickSort(struct seqlist *L, int low, int high)
{
    if (low < high)
    {
        int left = low;
        int right = high;
        int temp = L->elem[low];
        while (left < right)
        {
            while(left < right && L->elem[right] >= temp)     // ���������ҵ�һ��С��temp����
            {
                right--;
            }
 
            if(left < right)
            {
                L->elem[left++] = L->elem[right];
            }
 
            while(left < right && L->elem[left] < temp)      // ���������ҵ�һ�����ڵ���temp����
            {
                left++;
            }
 
            if(left < right)
            {
                L->elem[right--] = L->elem[left];
            }
        }
 
        L->elem[left] = temp;
 
        // �ݹ����
        QuickSort(L, low, left - 1);     // ����temp���
        QuickSort(L, right + 1, high);    // ����temp�ұ�
    }
}


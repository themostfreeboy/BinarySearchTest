#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define N 100

int comp(const void*a,const void*b)
{
	return *((int*)a)-*((int*)b);
}

int binarySearch(int data[],int left,int right,int target)
{
	if(left>right)	return -1;
	int mid=left+(right-left)/2;
	if(data[mid]==target)
	{
		return mid;
	}
	else if(data[mid]>target)
	{
		return binarySearch(data,left,mid-1,target);
	}
	else if(data[mid]<target)
	{
		return binarySearch(data,mid+1,right,target);
	}
	return -1;
}

int binarySearch2(int data[],int n,int target)
{
	int left=0,right=n-1,mid;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(data[mid]==target)
		{
			return mid;
		}
		else if(data[mid]>target)
		{
			right=mid-1;
		}
		else if(data[mid]<target)
		{
			left=mid+1;
		}
	}
	return -1;
}

int main()
{
	int data[N],i,index,findIndex,temp;
	bool flag[10*N];
	srand((unsigned)time(NULL));
	while(1)
	{
		memset(flag,false,10*N*sizeof(bool));
		for(i=0;i<N;i++)
		{
			do
			{
				temp=rand()%(10*N);
			}while(flag[temp]);
			flag[temp]=true;
			data[i]=temp;
		}
		qsort(data,N,sizeof(int),comp);
		printf("原始数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		index=rand()%N;
		findIndex=binarySearch(data,0,N-1,data[index]);
		//findIndex=binarySearch2(data,N,data[index]);
		if(findIndex==index)
		{
			printf("正确找到下标为%d的数%d\n",index,data[index]);
		}
		else
		{
			printf("未正确找到待找数%d，正确下标为%d，实际找到的下标为%d\n",data[index],index,findIndex);
		}
		system("pause");
	}
	return 0;
}
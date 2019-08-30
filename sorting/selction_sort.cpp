#include<iostream>

using namespace std;

void swap(int*a,int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void selctionsort(int*arr,int n)
{
	int min,i,j;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n*;j++)
		{
			if(arr[j]<arr[min])
			{
				swap(&arr[j],&arr[min]);
			}
		}
	}
}

void print(int*arr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int n,i;
	int*arr;
	scanf("%d",&n);
	arr=new int[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selctionsort(arr,n);
	print(arr,n);
	return 0;
}
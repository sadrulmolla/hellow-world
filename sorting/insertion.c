#include<stdio.h>
#include<stdlib.h>
void insertion(int,int*);
void insertion(int n,int*arr)
{
	int i,j,key;
	for(i=0;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0&&key>arr[j])
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main(void)
{
	int n,*arr,i;
	printf("Enter the size of arry:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion(n,arr);
}
	

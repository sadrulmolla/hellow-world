#include<iostream>

using namespace std;

void merge(int*arr,int l,int m,int r)
{
	int i,j,k;
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(i=0;i<n2;i++)
		R[i]=arr[m+i+1];
	i=0;j=0;k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]>R[j])
		{
			arr[k]=R[j];
			j++;
		}
		else
		{
			arr[k]=L[i];
			i++;
		}
		k++;
	}
	if(i!=n1)
	{
		while(i<n1)
		{
			arr[k]=L[i];
			i++;
			k++;
		}
	}
	if(j!=n2)
	{
		while(j<n2)
		{
			arr[k]=R[j];
			j++;
			k++;
		}
	}
}

void mergesort(int*arr,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int*arr;
	arr=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	cout<<endl;
	return 0;
}
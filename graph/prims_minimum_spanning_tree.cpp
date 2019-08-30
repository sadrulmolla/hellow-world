#include<iostream>
#include<climits>

int getmin(int*key,bool*mstset,int n)
{
	int min=INT_MAX;
	int min_index;
	for(int i=0;i<n;i++)
	{
		if(mstset[i]==false && key[i]<min)
		{
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}

int minumumspaningtree(int**graph,int n)
{
	int parents[n],i,j;
	bool mstset[n];
	int key[n];
	for(i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	key[0]=0;
	parents[0]=-1;
	for(i=0;i<n-1;i++)
	{
		int u=getmin(key,mstset,n);
		mstset[u]=true;
		for(j=0;j<n;j++)
		{
			if(graph[u][j] && mstset[j]==false && graph[u][j]<key[j])
			{
				parents[j]=u;
				key[j]=graph[u][j];
			}
		}
	}
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=key[i];
	}
	return sum;
}

int main(void)
{
	int**graph;
	int i,n,j;
	scanf("%d",&n);
	graph=new int*[n];
	for(i=0;i<n;i++)
	{
		graph[i]=new int[n];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("%d\n",minumumspaningtree(graph,n));
	return 0;
}
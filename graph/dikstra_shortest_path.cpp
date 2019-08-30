#include<iostream>
#include<climits>

using namespace std;

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

void minimumcost(int**graph,int n)
{
	int key[n];
	int i,j;
	bool mstset[n];
	for(i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	key[0]=0;
	for(i=0;i<n-1;i++)
	{
		int u=getmin(key,mstset,n);
		mstset[u]=true;
		for(j=0;j<n;j++)
		{
			if(mstset[j]==false && graph[u][j] && (graph[u][j]+key[u])<key[j])
			{
				key[j]=graph[u][j]+key[u];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",key[i]);
	}
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
	minimumcost(graph,n);
}
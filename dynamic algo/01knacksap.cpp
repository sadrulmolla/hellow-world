#include<iostream>
#include <algorithm>

using namespace std;

#define forn(i,n) for(i=0;i<n;i++)

int32_t main(void)
{
	int n,i,max_we,j;
	cin>>n;
	int*weight=new int[n];
	int*cost=new int[n];
	forn(i,n)
	{
		cin>>weight[i];
	}
	forn(i,n)
	{
		cin>>cost[i];
	}
	cin>>max_we;
	int*d=new int[max_we+1];
	int*prev=new int[max_we+1];
	forn(j,max_we+1)
	{
		prev[j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=max_we;j++)
		{
			if(i==0||j==0)d[j]=0;
			else if(j==weight[i-1])
			{
				d[j]=max(prev[j],cost[i-1]);
			}
			else if(j<weight[i-1])
			{
				d[j]=prev[j];
			}
			else
			{
				d[j]=max(prev[j],prev[j-weight[i-1]]+cost[i-1]);
			}
		}
		forn(j,max_we+1)
		{
			prev[j]=d[j];
			cout<<d[j]<<" ";
		}
		cout<<endl;
	}
	cout<<d[max_we]<<endl;
	delete []weight;
	delete []cost;
	delete []d;
	delete []prev;
	return 0;
}
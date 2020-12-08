#include<iostream>

using namespace std;
#define forn(i,n) for(i=0;i<n;i++)

int solve(int*a,int n)
{
	int i;
	int*freq=new int[n];
	int*max_sub=new int[n];
	freq[0]=1;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i-1])freq[i]=freq[i-1]+1;
		else freq[i]=1;
	}
	max_sub[0]=1;
	for(i=1;i<n;i++)
	{
		if(freq[i]==1)
		{
			if(a[i-2]+1<a[i])max_sub[i]=freq[i-1]+1;
			else if(a[i-2]<a[i]-1)max_sub[i]=freq[i-1]+1;
			else max_sub[i]=freq[i];
		}
		else
		{
			max_sub[i]=max_sub[i-1]+1;
		}
	}
	forn(i,n)
	{
		cout<<max_sub[i]<<" ";
	}
	cout<<endl;
	return 0;
}

int32_t main(void)
{
	int n,i;
	cin>>n;
	int*a=new int [n];
	forn(i,n)
	{
		cin>>a[i];
	}
	int ans=solve(a,n); 
	delete []a;

}
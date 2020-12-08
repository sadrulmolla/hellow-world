bool myfun(vector<int>&v1,vector<int>&v2)
{
	return (v1[2]>v2[2]);
}
int find(vector<int>&prents,int x)
{
    if(prents[x]==-1)return x;
    else return find(prents,prents[x]);
    //return 0;
}
long kruskals(int n,vector<vector<int>>&edges)
{
    sort(edges.begin(),edges.end(),myfun);
    vector<int>prents(n);
    int i,x,y;
    long sum=0;
    for(i=0;i<=n;i++)
    {
        prents[i]=-1;
    }
    int e=edges.size();
    for(i=0;i<e;i++)
    {
        x=find(prents,edges[i][0]);
        y=find(prents,edges[i][1]);
        if(x!=y)
        {
            sum+=edges[i][2];
            prents[x]=y;
        }
    }
    return sum;
}
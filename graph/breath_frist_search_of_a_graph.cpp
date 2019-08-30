#include<iostream>
#include<queue>
#include<list>

using namespace std;

class graph
{
	int V;
	list<int>*adj;
public:
	graph(int v)
	{
		this->V=v;
		adj=new list<int>[v];
	}
	void addedg(int s,int w)
	{
		adj[s].push_back(w);
	}
	void bfs(int v)
	{
		bool*visited;
		int x;
		visited=new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;
		}
		queue<int>q;
		q.push(v);
		visited[v]=true;
		while(!q.empty())
		{
			x=q.front();
			cout<<x<<" ";
			q.pop();
			for(auto it=adj[x].begin();it!=adj[x].end();it++)
			{
				if(!visited[*it])
				{
					q.push(*it);
					visited[*it]=true;
				}
			}
		}
	}
};

int main(void)
{
	int n,e,src,des,str;
	scanf("%d %d",&n,&e);
	graph gr(n);
	for(int i=0;i<e;i++)
	{
		scanf("%d %d",&src,&des);
		gr.addedg(src,des);
	}
	scanf("%d",&str);
	gr.bfs(str);
	cout<<endl;
	return 0;
}
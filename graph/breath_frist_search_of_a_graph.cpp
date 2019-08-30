#include<iostream>
#include<queue>
#include<list>

using namespace std;

class graph
{
	int V;//number of nodes in the graph
	list<int>*adj; //array of list for save all the adjacent node of a node
public:
	graph(int v)
	{
		this->V=v;
		adj=new list<int>[v];//making a array of list of size V ,one list for each node 
	}
	void addedg(int s,int w)
	{
		adj[s].push_back(w);//s node is adjacent to w
	}
	void bfs(int v)
	{
		bool*visited;//boolean array to mark a array visited once it visted
		int x;
		visited=new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;//initialy all the nodes are unvisited
		}
		queue<int>q;//make a queue to save the all next nodes that we have to visit
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
#include<iostream>
#include<cstring>

using namespace std;

class edges
{
public:
	int src,end;
};
class graph
{
public:
	int V,E;
	edges*edg;
};

void Union(int*parents,int x,int y)
{
	//int xset = find(parents,x);  
    //int yset = find(parents,y); 
	if(x!=y)
	{
		parents[x]=y;
	}	
}

int find(int*parents,int n)
{
	int p=parents[n];
	if(p<0)
		return n;
	else
		return find(parents,p);
}

bool is_cycle(graph*gr)
{
	int v=gr->V;
	int e=gr->E;
	int x,y;
	int*parents=new int[v];
	memset(parents,-1,sizeof(int)*v);
	for(int i=0;i<e;i++)
	{
		x=find(parents,gr->edg[i].src);
		y=find(parents,gr->edg[i].end);
		if(x==y)
			return true;
		Union(parents,x,y);
	}
	return false;
}

graph*creategrpag(int v,int e)
{
	graph*gr=new graph();
	gr->V=v;
	gr->E=e;
	gr->edg=new edges[e*sizeof(edges)];
	return gr;
}

int main(void)
{
	int n,e,x,y;
	printf("Enter The Numnber of Vertex and \n");
	scanf("%d %d",&n,&e);
	graph*gr=creategrpag(n,e);
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		gr->edg[i].src=x;
		gr->edg[i].end=y;
	}
	if(is_cycle(gr))
	{
		printf("There is Cycle in the graph\n");
	}
	else
	{
		printf("There is no Cycle in the graph\n");
	}
}
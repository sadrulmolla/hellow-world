#include<iostream>
#include<queue>
#include<stack>

using namespace std;

typedef struct node
{
	int data;
	struct node*left,*right;
}node;

node*root=NULL;

node*newnode(int x)
{
	node*temp=new node;
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}

void inorder(node*temp)
{
	stack<node*>s;
	node*p=temp;
	while(!s.empty() || p!=NULL)
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}
		p=s.top();
		s.pop();
		cout<<p->data<<" ";
		p=p->right;
	}
}

void insert(int x)
{
	if(root==NULL)
	{
		root=newnode(x);
		return;
	}
	queue<node*>q;
	node*temp=NULL;
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->left==NULL)
		{
			temp->left=newnode(x);
			return;
		}
		else
		{
			q.push(temp->left);
		}
		if(temp->right==NULL)
		{
			temp->right=newnode(x);
			return;
		}
		else
		{
			q.push(temp->right);
		}
	}
}

int main(void)
{
	int key,n,i;
	cout<<"Enter The Number Of Elements: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		printf("Enter A Value:");
		scanf("%d",&key);
		insert(key);
	}
	inorder(root);
	cout<<"\n";
}
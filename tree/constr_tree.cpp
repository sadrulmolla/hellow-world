/*Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where every node has either
0 or 2 children. One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in 
‘preLN[]’ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the
corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.*/
#include<iostream>
#include<stack>

using namespace std;

typedef struct node
{
	int data;
	struct node*left,*right;
}node;

node*newnode(int x)
{
	node*temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node*constr(int*pre,char*preLN,int n,int*index_ptr)
{
	if(*index_ptr==n)
		return NULL;
	int i=*index_ptr;
	node*temp;
	temp=newnode(pre[i]);
	(*index_ptr)++;
	if(preLN[i]='N')
	{
		temp->left=constr(pre,preLN,n,index_ptr);
		temp->right=constr(pre,preLN,n,index_ptr);
	}
	return temp;
}

node*construct_tree(int*pre,char*preLN,int n)
{
	int index=0;
	return constr(pre,preLN,n,&index);
}

void printInorder(node*temp)
{
	stack<node*>s;
	node*p=NULL;
	s.push(temp);
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		while(p)
		{
			cout<<p->data<<"\t";
			s.push(p->right);
			s.push(p->left);
			p=s.top();
			s.pop();
		}
	}
}

int main(void)
{
	int n;
	int*pre;
	char*preLN;
	node*root;
	printf("Enter Number Element: ");
	scanf("%d",&n);
	pre=new int[n];
	preLN=new char[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%c ",&preLN[i]);
	}
	root=construct_tree(pre,preLN,n);
	printInorder(root);
	return 0;
}
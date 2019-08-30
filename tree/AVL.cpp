#include<iostream>
#include<algorithm>

using namespace std;

typedef struct node
{
	int data;
	struct node*left,*right;
	int height;
}node;

node*newnode(int k)
{
	node*temp=new node;
	temp->data=k;
	temp->height=1;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int heigh(node*root)
{
	if(root==NULL)
		return 0;
	else
		return root->height;
}

int getbal(node*root)
{
	int bal=(heigh(root->left))-(heigh(root->right));
	return bal;
}

node*leftrotate(node*x)
{
	node*y=x->right;
	node*t2=y->left;
	x->right=t2;
	y->left=x;
	y->height = max(heigh(y->left), 
                    heigh(y->right)) + 1;  
    x->height = max(heigh(x->left), 
                    heigh(x->right)) + 1;
	return y;
}

node*rightrotate(node*x)
{
	node*y=x->left;
	node*t2=y->right;
	x->left=t2;
	y->right=x;
	y->height = max(heigh(y->left), 
                    heigh(y->right)) + 1;  
    x->height = max(heigh(x->left), 
                    heigh(x->right)) + 1;
	return y;
}

node*insert(node*root,int key)
{
	if(root==NULL)
	{
		return newnode(key);
	}
	else if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=insert(root->right,key);
	}
	else
	{
		return root;
	}
	root->height=1+max(heigh(root->left),heigh(root->right));
	int balence=getbal(root);
	if(balence>1 && key<root->left->data)
	{
		return rightrotate(root);
	}
	else if(balence<-1 && key>root->right->data)
	{
		return leftrotate(root);
	}
	else if(balence>1 && key>root->left->data)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	else if(balence<-1 && key<root->right->data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}

void preorder(node*root)
{
	if(root==NULL)
		return;
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}

int main(void)
{
	int n,x;
	scanf("%d",&n);
	node*root=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=insert(root,x);
	}
	preorder(root);
	return 0;
}
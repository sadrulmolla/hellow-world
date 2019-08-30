#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//-------------declearing the node --------------------

typedef struct node
{
	int data;
	struct node*left,*right;
}node;



//function to insert the elements----------------------------

void insert(node*root,int x)
{
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		if(x<root->data)root->left=insert(x);
		else insert->right=insert(x);
	}
}

//-----------------function to search for a key----------------------------------

bool search(root,x)
{
	if(root==NULL)return 0;
	else if(root==x)return 1;
	else if(x<root->data)return search(root->left,x);
	else if(x>root->data)return search(root->right,x);
}

//----------------function to create the binary srearch tree------------------------------

void creat()
{
	int n,i,x;
	node*root=NULL;//creating empty binary tree
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the valu of %d th node:");
		scanf("%d",&x);
		root=insert(root,x);
	}
	printf("Enter the number to search:");
	scanf("%p",&p);
	if(search(root,p))
	{
		printf("Found\n");
	}
	else
	{
		printf("NotFound\n");
	}
}

//--------------------------main function start----------------------

int main(void)
{
	creat();
}
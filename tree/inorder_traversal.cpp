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
    node*temp=NULL;
    temp=new node;
    temp->data=x;
    return temp;

}

node*insert(node*root,int x)
{
    if(root==NULL)
    {
        root=newnode(x);
        return root;
    }
    else
    {
        stack<node*>s;
        s.push(root);
        node*temp=NULL;
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->left==NULL)
            {
                temp->left=newnode(x);
                return root;
            }
            else
            {
                s.push(temp->left);
            }
            if(temp->right==NULL)
            {
                temp->right=newnode(x);
                return root;
            }
            else
            {
                s.push(temp->right);
            }
        }
    }
}

void inoder(node*root)
{
    if(root==NULL)
        return;
    inoder(root->left);
    printf("%d\n",root->data);
    inoder(root->right);
}


int main(void)
{
    int n,x;
    printf("Enter The Number Of Nodes: ");
    scanf("%d",&n);
    node*root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    inoder(root);
    return 0;
}

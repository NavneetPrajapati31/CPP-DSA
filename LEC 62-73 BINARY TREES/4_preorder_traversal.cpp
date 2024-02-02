//preorder traversal : NLR -> NODE LEFT RIGHT


#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }

};

node* buildtree(node* root)
{
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"enter data to insert at left of "<<data<<endl;
    root->left = buildtree(root->left);

    cout<<"enter data to insert at right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}


void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}


int main()
{
    node* root = NULL;
    root = buildtree(root);

    preorder(root);

}
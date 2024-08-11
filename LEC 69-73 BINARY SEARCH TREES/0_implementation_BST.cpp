#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insert(node* &root, int d)
{
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right =  insert(root->right,d);
    }

    else
    {
        root->left = insert(root->left,d);
    }

    return root;
}



void takeInput(node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insert(root,data);
        cin>>data;
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int min(node* root)
{
    node* temp = root;
    while(temp->left)
    {
        temp = temp->left;
    }

    return temp->data;
}

int max(node* root)
{
    node* temp = root;
    while(temp->right)
    {
        temp = temp->right;
    }

    return temp->data;
}

node* deleteNode(node* &root, int target)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == target)
    {
    if(root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    else if(root->left!=NULL && root->right == NULL)
    {
        node* temp = root->left;
        delete root;
        return temp;
    }

    else if(root->left == NULL && root->right!= NULL)
    {
        node* temp = root->right;
        delete root;
        return temp;
    }

    else
    {
        int mini = min(root->right);
        root->data = mini;
        deleteNode(root->right,mini);
        return root;
    }

    }

    else if(root->data < target)
    {
        root->right = deleteNode(root->right,target);
        return root;
    }

    else
    {
        root->left = deleteNode(root->left,target);
        return root;
    }
}

int main()
{
    node* root = NULL;
    takeInput(root);
    inorder(root);

    cout<<endl;

    cout<<min(root)<<endl;
    cout<<max(root)<<endl;

    root = deleteNode(root,10);

    inorder(root);
}
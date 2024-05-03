#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* right;
    node* left;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }

};

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
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

node* insert(node* &root, int d)
{
    if(root == NULL)
    {
        root = new node(d);

    }

    if(root->data < d)
    {
        root->right = insert(root->right,d);
        
    }

    if(root->data > d)
    {
        root->left = insert(root->left, d);
        
    }

    return root;

}

void input(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insert(root,data);
        cin>>data;
    }

}

int max(node* root)
{
    node* temp = root;

    while(temp->right!= NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

int min(node* root)
{
    node* temp = root;

    while(temp->left!= NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int main()
{
    node* root = NULL;
    input(root);
    inorder(root);

    cout<<endl;

    cout<<max(root)<<endl;
    cout<<min(root);

}
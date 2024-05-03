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

node* insert(node* root, int d)
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


node* min(node* root)
{
    node* temp = root;

    while(temp->left!= NULL)
    {
        temp = temp->left;
    }

    return temp;
}

node* deleteval(node* root, int d)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == d)
    {
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left!= NULL && root->right== NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;

        }

        if(root->left== NULL && root->right!= NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right!= NULL && root->left!= NULL)
        {
            int minval = min(root->right)->data;
            root->data = minval;
            root->right = deleteval(root->right,minval);
            return root;
        }
    }

    else if(root->data > d)
    {
        root->left = deleteval(root->left,d);
    }

    else if(root->data < d)
    {
         root->right = deleteval(root->right,d);
    }

    return root;
}

int main()
{
    node* root = NULL;
    input(root);

    inorder(root);

    root = deleteval(root,55);

    inorder(root);

}
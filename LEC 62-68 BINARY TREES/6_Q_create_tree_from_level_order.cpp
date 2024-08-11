//create a binary tree from level order traversal


#include<iostream>
#include<queue>
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


void buildfromlevel(node* root)
{
    queue<node*> q;
    cout<<"enter data for root"<<endl;

    int data;
    cin>>data;

    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"enter left data for "<<temp->data;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1)
        {
            temp->left = new node(leftdata);
        }

         cout<<"enter right data for "<<temp->data;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1)
        {
            temp->left = new node(rightdata);
        }
    }
}


int main()
{
    node* root = NULL;
    buildfromlevel(root);
}
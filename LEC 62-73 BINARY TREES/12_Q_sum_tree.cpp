//Sum Tree or Not : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbk1JcENFS181UnQ2SjRJam9lVXRrcjlpbVNqZ3xBQ3Jtc0tucGp3Rkp5ZkRRMXZDb0RGb0hUUFUybzFVS1BtTjZxTlNsdDJfM2NwbWFKNUp2amFIbjFXQXJZNkJwbE5Fb09wTkJaRGpsVHF3eHlEUEx5SnYtdVctQldUcjZmOURfMURmVlhjZWtSSEhuM3luTDdKVQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fsum-tree%2F1&v=nHMQ33LZ6oA

#include<iostream>
#include<algorithm>
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


pair<bool,int> sumtree(node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true,root->data);
        return p;       
    }

    pair<bool,int> leftans = sumtree(root->left);
    pair<bool,int>  rightans = sumtree(root->right);

    bool left = leftans.first;
    bool right = rightans.first;

    bool condition = root->data == leftans.second + rightans.second;

    pair<bool,int> ans;

    if(left && right && condition)
    {
        ans.first = true;
        ans.second = 2*root->data;
    }

    else
    ans.first = false;

    return ans;
}

bool checksumtree(node* root)
{
    return sumtree(root).first;
}
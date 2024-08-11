//Height of Tree : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa2x3WFZNUV9pWUZ5T1pTTjhfSC1xR2I5ZDdPd3xBQ3Jtc0ttbF9lcmYyd2t1Q2pRdWpSZkFHdWRRYTNtM1FCY3I3NHVKTk5vd2tGb21hSmxQWWF2bDM2VlBBbkRlVzdpM0RuQXpuaURCb3dHUnR1cU4tVXJoOFcwSm50WnktdlNXWXRKZG5yQm11VG83eVUxaGh2OA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fheight-of-binary-tree%2F1&v=nHMQ33LZ6oA

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

int heightOfBinaryTree(node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int right = heightOfBinaryTree(root->right);
    int left = heightOfBinaryTree(root->left);

    int ans = max(right,left)+1;

    return ans;
}
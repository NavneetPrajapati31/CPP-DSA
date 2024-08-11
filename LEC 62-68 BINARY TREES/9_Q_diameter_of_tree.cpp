//Diameter of Tree : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbUNBRzV0M1ptVFRSWU1IYU9haG9MbXl0ZC1Id3xBQ3Jtc0tuUGRkbmxReUFIR0tyZURMcW5PeVhZOUlwVi0xZU56VDg5VkdZd2hMbXRKamxFcVBickp5ZFI1YWF3Q0F6ZXJ0ZDd1dWNDWU5mSHNFaGJnRXhwb3d5UHFHMVJpNzV2Rnd5elNxa0Rac3RJNFZnYmdPdw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fdiameter-of-binary-tree%2F1&v=nHMQ33LZ6oA

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

int diameter(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->right);
    int op2 = diameter(root->left);
    int op3 = heightOfBinaryTree(root->right)+heightOfBinaryTree(root->left)+1;

    int ans = max(op1,max(op2,op3));

    return ans;

}

pair<int,int> diameterfast(node* root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
    }

    pair<int,int> first = diameterfast(root->left);
    pair<int,int> second = diameterfast(root->right);

    int op1 = diameterfast(root->left).first;
    int op2 = diameterfast(root->right).first;

    int op3 = diameterfast(root->left).second + diameterfast(root->right).second+1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = heightOfBinaryTree(root->right)+heightOfBinaryTree(root->left) + 1;

    return ans;

}
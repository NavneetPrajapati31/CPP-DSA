//Balanced Tree or Not : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa1VQbnBBUURHYTFoNGhHdm91ZDBVcE5Cc2JjQXxBQ3Jtc0trdzZsM094VWc5WnZqZ0xtZ2p5eDVEd1BXWktsdlRQcGFkeGtGbUhaR2tQOU5BZFJ3SFdVeF95Qng4azhOaHk2ZzJxdXROTHVmV0NmMnhJczdxaENqVDhibTJTZEJwQWZDQW16U015WjFHNHBJbm0yRQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fcheck-for-balanced-tree%2F1&v=nHMQ33LZ6oA

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


bool isBalancedBT(node* root)
{
    if(root == NULL)
    {
        return true;
    }

    bool left = isBalancedBT(root->left);
    bool right =isBalancedBT(root->right);

    int leftheight=heightOfBinaryTree(root->left);
    int rightheight = heightOfBinaryTree(root->right);

    if(abs(leftheight-rightheight)<=1 && left && right)
    {
        return true;
    }

    else
    return false;
}


pair<bool,int> isBalancedfast(node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalancedfast(root->left);
    pair<bool,int> right = isBalancedfast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    int diff = abs(left.second = right.second)<=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;

    if(diff && leftans && rightans)
    {
        ans.first = true;
    }

    else
    ans.first = false;

    return ans;
}
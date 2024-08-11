//

#include<iostream>
using namespace std;

bool valid(BinaryTreeNode<int> *root, int min, int max)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data >= min && root->data <=max)
    {
        bool left = valid(root->left,min,root->data);
        bool right = valid(root->right,root->data,max);

        return left && right;
    }

    else
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) 
{
    return valid(root,INT_MIN,INT_MAX);
}
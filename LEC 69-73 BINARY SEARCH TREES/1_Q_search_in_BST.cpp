//https://www.naukri.com/code360/problems/search-in-bst_1402878?leftPanelTabValue=PROBLEM

#include<iostream>
using namespace std;

bool searchInBST(BinaryTreeNode<int> *root, int x) 
{
    if(root == NULL)
    {
        return false;
    }

        if(root->data == x)
        {
            return true;
        }

        else if(root->data>x)
        {
            return searchInBST(root->left, x);
        }

        else
        {
            return searchInBST(root->right,x);
        }
}
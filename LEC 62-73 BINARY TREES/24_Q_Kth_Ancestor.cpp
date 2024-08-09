//https://www.naukri.com/code360/problems/-kth-ancestor-of-a-node-in-binary-tree_842561

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode
    {
    public :
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

BinaryTreeNode *solve(BinaryTreeNode *root, int node, int &k)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == node)
    {
        return root;
    }

    BinaryTreeNode *leftAns = solve(root->left,node,k);
    BinaryTreeNode *rightAns = solve(root->right,node,k);

    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }

        return leftAns;
    }

    else if(rightAns != NULL && leftAns == NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int findKthAncestor(BinaryTreeNode *root, int targetNodeVal, int k) {
    // Write your code here.
    BinaryTreeNode *ans = solve(root,targetNodeVal,k);
    if(ans == NULL || ans->data == targetNodeVal)
    {
        return -1;
    }

    else
    {
        return ans->data;
    }
}
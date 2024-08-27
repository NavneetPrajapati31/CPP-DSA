//Code 360 : https://www.naukri.com/code360/problems/is-binary-heap-tree_893136?leftPanelTabValue=PROBLEM
//Leetcode : https://leetcode.com/problems/check-completeness-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode 
    {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

int countNodes(BinaryTreeNode<int>* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int ans =  1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }

    bool checkCBT(BinaryTreeNode<int>*root , int i, int count)
    {
        if(root == NULL)
        {
            return true;
        }

        if(i>=count)
        {
            return false;
        }

        else
        {
            bool left = checkCBT(root->left, 2*i+1, count);
            bool right = checkCBT(root->right, 2*i+2, count);

            return (left && right);
        }
    }

    bool isMax(BinaryTreeNode<int>*root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return true;
        }

        if(root->right == NULL)
        {
            return root->data >= root->left->data;
        }

        else
        {
            return (root->data >= root->left->data && root->data >= root->right->data && isMax(root->left) && isMax(root->right));
        }
    }

bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    // Write your code here.
    int index = 0;
    int totalcount = countNodes(root);
    if(checkCBT(root, index, totalcount) && isMax(root))
    {
        return true;
    }

    else
     return false;
}
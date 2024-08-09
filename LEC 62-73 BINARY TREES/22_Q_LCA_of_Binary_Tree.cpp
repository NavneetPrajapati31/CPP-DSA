//LCA : https://www.naukri.com/code360/problems/lca-of-binary-tree_920541

#include<iostream>
using namespace std;
template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

TreeNode<int> *solve(TreeNode<int> *root, int x, int y)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == x || root->data == y)
    {
        return root;
    }

    TreeNode<int> *leftAns = solve(root->left,x,y);
    TreeNode<int> *rightAns = solve(root->right,x,y);

    if(leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }

    else if(rightAns != NULL && leftAns == NULL)
    {
        return rightAns;
    }

    else if(rightAns == NULL && leftAns == NULL)
    {
        return NULL;
    }

    else if(rightAns != NULL && leftAns != NULL)
    {
        return root;
    }

}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int> * ans =  solve(root,x,y);
    return ans->data;
}
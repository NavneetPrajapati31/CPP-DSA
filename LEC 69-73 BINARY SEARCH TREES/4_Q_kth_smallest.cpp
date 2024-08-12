//https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

int solve(BinaryTreeNode<int>* root, int k, int &i)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = solve(root->left,k,i);

    if(left != -1)
    {
        return left;
    }

    i++;
    if(i == k)
    {
        return root->data;
    }

    solve(root->right,k,i);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) 
{
    int i=0;
    return solve(root,k,i);
}
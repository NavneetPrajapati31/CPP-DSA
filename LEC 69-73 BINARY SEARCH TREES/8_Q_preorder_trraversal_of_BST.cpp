//https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111?leftPanelTab=0

BinaryTreeNode<int>* solve(vector<int> &pre, int &i, int min, int max)
{
    if(i>=pre.size())
     return NULL;

    if(pre[i] > max || pre[i]<min)
    {
        return NULL;
    }

    BinaryTreeNode<int>* node = new BinaryTreeNode<int>(pre[i++]);
    node->left = solve(pre,i,min,node->data);
    node->right = solve(pre,i,node->data,max);

    return node;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i=0;
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return solve(preorder,i,mini,maxi);
}
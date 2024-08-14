//https://www.naukri.com    /code360/problems/largest-bst-subtree_893103?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

class info
{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};


info solve(TreeNode * root, int &ans)
{
    if(root == NULL)
     return {INT_MIN,INT_MAX,true,0};

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currentNode;

    currentNode.size = left.size + right.size +1;
    currentNode.maxi = max(root->data, right.maxi);
    currentNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currentNode.isBST = true;
    }

    else
     currentNode.isBST = false;

    if(currentNode.isBST)
    {
        ans = max(ans,currentNode.size);
    }

    return currentNode;

}


int largestBST(TreeNode * root)
{
    int ans=0;
    info temp = solve(root, ans);
    return ans;
}
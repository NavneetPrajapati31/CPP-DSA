//https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

void inorder(TreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* solve(vector<int> in, int s, int e)
{
    if(s>e)
     return NULL;

    int mid = s+(e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);

    root->right = solve(in,mid+1,e);
    root->left = solve(in,s,mid-1);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root)
{
    // Write your code here.
    vector<int> in;
    inorder(root,in);

    return solve(in,0,in.size()-1);
}
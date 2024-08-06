//Right view: https://www.naukri.com/code360/problems/right-view_764605?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM

void solve(BinaryTreeNode<int>* root, vector<int> &ans, int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}

vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}
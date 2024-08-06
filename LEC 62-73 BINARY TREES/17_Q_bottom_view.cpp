//Bottom view: https://www.naukri.com/code360/problems/bottom-view-of-binary-tree_893110?leftPanelTabValue=PROBLEM

vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    
    map<int,int> nodes;
    queue<pair<TreeNode<int>*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<TreeNode<int>*,int> temp = q.front();
        q.pop();

        TreeNode<int>* frontNode = temp.first;
        int hd = temp.second;

            nodes[hd]=frontNode->data;

        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i:nodes)
    {
            ans.push_back(i.second);
    }
    return ans;
}
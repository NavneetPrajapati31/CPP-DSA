//Boundary Traversal: https://www.naukri.com/code360/problems/boundary-traversal_790725

void traverseLeft(TreeNode<int>* root, vector<int> &ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if(root->left)
    {
        traverseLeft(root->left, ans);
    }

    else if(root->right)
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(TreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode<int>* root, vector<int> &ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    
    if(root->right)
    {
        traverseRight(root->right, ans);
    }

    else if(root->left)
    {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;

    if(root==NULL)
    {
        return ans;
    }

    ans.push_back(root->data);
    
    traverseLeft(root->left,ans);

    traverseLeaf(root->left,ans);

    traverseLeaf(root->right,ans);

    traverseRight(root->right,ans);

    return ans;
}
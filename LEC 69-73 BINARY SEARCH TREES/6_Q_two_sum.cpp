//https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631?leftPanelTab=0&leftPanelTabValue=SUBMISSION

void inorder(BinaryTreeNode<int>* root, vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> in;
    inorder(root, in);

    int i=0,j=in.size()-1;

    while(i<j)
    {
        if(in[i]+in[j] == target)
        {
            return true;
        }

        else if(in[i]+in[j] > target)
        {
            j--;
        }

        else
        {
            i++;
        }
    }

    return false;
}
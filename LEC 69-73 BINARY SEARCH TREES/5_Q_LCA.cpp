//https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    TreeNode *temp = root;

    while(temp!=NULL)
    {
        if((temp->data > P->data)&&(temp->data > Q->data))
        {
            temp = temp->left;
        }

        else if((temp->data < P->data)&&(temp->data < Q->data))
        {
            temp = temp->right;
        }

        else
        {
            return temp;
        }
    }
}
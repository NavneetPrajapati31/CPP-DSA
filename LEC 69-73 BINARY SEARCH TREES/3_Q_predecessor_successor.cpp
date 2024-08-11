//https://www.naukri.com/code360/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode *temp = root;
    int pred=-1;
    int succ=-1;

    while(temp->data != key)
    {
        if(temp->data < key)
        {
            pred = temp->data;
            temp = temp->right;
        }

        else
        {
            succ = temp->data;
            temp = temp->left;
        }
    }

    TreeNode *leftTree = temp->left;
    while(leftTree!=NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode *rightTree = temp->right;
    while(rightTree!=NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred,succ};
}
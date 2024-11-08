//ZigZag Traversal: https://www.naukri.com/code360/problems/zig-zag-traversal_1062662

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }

    bool lefttoRight = true;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        

        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int> * frontNode = q.front();
            q.pop();

            int index = lefttoRight? i:size-i-1;

            ans[index] = frontNode->data;

            if(frontNode->left)
            {
                q.push(frontNode->left);
            }

            if(frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        lefttoRight = !lefttoRight;

        for(auto i:ans)
        {
            result.push_back(i);
        }
    }

    return result;

}
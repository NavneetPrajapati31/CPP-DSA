//https://www.naukri.com/code360/problems/time-to-burn-tree_630563?count=25&search=burn&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav

BinaryTreeNode<int>* createMapping(BinaryTreeNode<int>* root, int start, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mapping)
{
    BinaryTreeNode<int>* res = NULL;
    mapping[root] = NULL;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        if(front->data == start)
        {
            res = front;
        }

        if(front->left)
        {
            mapping[front->left] = front;
            q.push(front->left);
        }

        if(front->right)
        {
            mapping[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int solve(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mapping)
{
    map<BinaryTreeNode<int>*,bool> visited;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    visited[root] = true;
    int ans=0;
    
    while(!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if(front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if(mapping[front] && !visited[mapping[front]])
            {
                flag = true;
                q.push(mapping[front]);
                visited[mapping[front]] = true;
            }
        }

        if(flag == true)
        {
            ans++;
        }
    }

    return ans;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mapping;
    BinaryTreeNode<int>* target = createMapping(root,  start, mapping);

    return solve(target,mapping);
}
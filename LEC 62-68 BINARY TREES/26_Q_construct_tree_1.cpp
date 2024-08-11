//https://www.geeksforgeeks.org/problems/construct-tree-1/1

void createMapping(int inorder[], map<int,int> &mapping, int size)
{
    for(int i=0;i<size;i++)
    {
        mapping[inorder[i]] = i;
    }
}

Node*solve(int inorder[], int preorder[], int &index, int start, int end, int n, map<int,int> &mapping)
{
    if(index >= n || start>end)
    {
        return NULL;
    }

    int element = preorder[index++];
    Node* root = new Node(element);
    int pos = mapping[element];

    root->left = solve(inorder,preorder,index,start,pos-1,n,mapping);
    root->right = solve(inorder,preorder,index,pos+1,end,n,mapping);

    return root;
}
    
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        // Code here
            map<int,int> mapping;
    createMapping(inorder, mapping, n);

    int index=0;
    Node*ans = solve(inorder,preorder,index,0,n-1,n,mapping);
    return ans;
    }
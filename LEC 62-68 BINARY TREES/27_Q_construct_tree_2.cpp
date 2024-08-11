//https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

void createMapping(int inorder[], map<int,int> &mapping, int size)
{
    for(int i=0;i<size;i++)
    {
        mapping[inorder[i]] = i;
    }
}

Node*solve(int inorder[], int postorder[], int &index, int start, int end, int n, map<int,int> &mapping)
{
    if(index < n || start<end)
    {
        return NULL;
    }

    int element = postorder[index--];
    Node* root = new Node(element);
    int pos = mapping[element];

    root->right = solve(inorder,postorder,index,pos+1,end,n,mapping);
    root->left = solve(inorder,postorder,index,start,pos-1,n,mapping);
    return root;
}
    
    Node* buildTree(int inorder[],int postorder[], int n)
    {
    map<int,int> mapping;
    createMapping(inorder, mapping, n);
    int index=n-1;
    Node*ans = solve(inorder,postorder,index,0,n-1,n,mapping);
    return ans;
    }
//https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&count=25&search=merge&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav

void inorder(TreeNode* root, vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}


void convertIntoSortedDLL(TreeNode *root, TreeNode* &head)
{
    if(root == NULL)
    {
        return;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head!=NULL)
     head->left = root;

    head = root;

    convertIntoSortedDLL(root->left,head);
}


TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2)
{
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1!=NULL && head2!= NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }

            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }

        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }

            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1!=NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2!=NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}


int countNodes(TreeNode* head)
{
    int cnt=0;
    TreeNode* temp = head;
    while(temp!=NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}


TreeNode* sortedLLtoBST(TreeNode* &head,int n)
{
    if(n <=0 || head == NULL)
    {
        return NULL;
    }

    TreeNode* left = sortedLLtoBST(head,n/2);

    TreeNode* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLtoBST(head,n-n/2-1);
    return root;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    TreeNode * head = mergeLinkedList(head1,head2);

    int cnt = countNodes(head);
    TreeNode* root = sortedLLtoBST(head,cnt);

    vector<int> v;
    inorder(root,v);

    return v;
}
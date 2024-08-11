//https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        Node* curr = root;
        
        while(curr!=NULL)
        {
            if(curr->left)
            {
                Node* pred = curr->left;
                while(pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                
                else
                {
                    pred->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
            
            else
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        return ans;
    }
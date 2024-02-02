//Count Leaf Nodes : https://bit.ly/3Lyh6kC


#include<iostream>
#include<queue>
using namespace std;


class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }

};


void inorder(node * root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorder(root->right, count);

}


int noOfLeafNodes(node *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}
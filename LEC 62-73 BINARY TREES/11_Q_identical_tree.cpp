//Tree Identical or Not : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa09GZ1cxV1dxZHNqQW9TdEh1azJKWmJPM0pRQXxBQ3Jtc0trUk5samdUOXdkNnVIT2EzLUpCVmlKZ2RWdkI4OHZLRVdyTlpkVHI4Q1JyZGJCU0hhV2h1Qk4tZWRyejVsU2JDRkUyM1hiYzdUX0RQRVVwZHZ1am14RURSekNKRVBzWkFvRHJZWThKbGNoLVNqSEpmMA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fdetermine-if-two-trees-are-identical%2F1&v=nHMQ33LZ6oA

#include<iostream>
#include<algorithm>
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

node* buildtree(node* root)
{
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"enter data to insert at left of "<<data<<endl;
    root->left = buildtree(root->left);

    cout<<"enter data to insert at right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}

bool checkidentical(node* r1, node* r2)
{
    if(r1== NULL && r2 == NULL)
    {
        return true;
    }

    if(r1!=NULL && r2==NULL)
    {
        return false;
    }

    if(r1==NULL && r2!= NULL)
    {
        return false;
    }

    bool left = checkidentical(r1->left,r2->left);
    bool right= checkidentical(r1->right,r2->right);
    bool value = r1->data == r2->data;

    if(value && right && left)
    {
        return true;
    }

    else
    return false;

}
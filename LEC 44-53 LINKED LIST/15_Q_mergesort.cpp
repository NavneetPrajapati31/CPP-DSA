//Merge Sort Linked List:  https://bit.ly/3GsXWsz
// T.C. = O(nlogn)
// S.C. = O(logn)

#include<iostream>
#include<map>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    node* random;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};


void insertattail(node* &head, node* &tail, int d)
{
    node* temp = new node(d);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    else
    {
        tail->next= temp;
        tail = temp;
    }

}


void print(node* &head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp->next;
    }

    cout<<endl;

}

node* findmid(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

node* merge(node* right, node* left)
{
    if(right == NULL)
    {
        return left;
    }

    if(left == NULL)
    {
        return right;
    }

    node* ans = new node(-1);
    node* temp = ans;
    
    while(right!= NULL && left!= NULL)
    {
        if(right->data > left->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

    }

    while(right!= NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    while(left!= NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    ans = ans->next;
    return ans;

}


node* mergesort(node* head)
{
    //base case

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* middle = findmid(head);

    node* left = head;
    node* right = middle->next;
    middle->next = NULL;

    right = mergesort(right);
    left = mergesort(left);

    node* ans = merge(right,left);
    return ans;

}


int main()
{
    node* node1 = new node(15);
    node* head = node1;
    node* tail = node1;
    insertattail(head,tail,10);
    print(head);
    insertattail(head,tail,20);
    print(head);
    insertattail(head,tail,25);
    print(head);

    node* val = mergesort(head);
    print(val);
}
//Reverse a Linked List in K group: https://bit.ly/3r1rCIP


#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    //constructor
    
    node(int data)
    {
        this -> data = data;
        this -> next = NULL;

    }

    //destructor

    ~node()
    {
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;

    }


};

void insertathead(node* &head, int d)
{
    node* temp = new node(d);
    temp -> next = head;
    head = temp  ;
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

node* kreverse(node* &head, int k)
{
    //base condition

    if(head == NULL)
    {
        return NULL;
    }

    //step1 reverse first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;

    int cnt = 0;

    while(curr!= NULL && cnt < k)
    {
        next = curr -> next;                                                                                                                                                                                                                                                               
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //step2 recursion dekhega aage ka

    if(next != NULL)
    {
        head->next = kreverse(next,k);
    }

    //step3 return head of reversed list

    return prev;
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    insertathead(head,15);
    insertathead(head,20);
    insertathead(head,25);
    insertathead(head,30);
    insertathead(head,35);

    print(head);
    cout<<kreverse(head,2)->data<<endl;
}
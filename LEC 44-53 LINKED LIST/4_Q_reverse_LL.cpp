/*Reverse a Linked List: https://bit.ly/3H1lKov
approach 1 iterative
approach 2 recursive
approach 3 recursive
*/

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

void reverse(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        cout<<head->data<<endl;
        return;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
    }
    head = prev;
    print(head);
    
}

void reverse1(node* &head, node* &curr, node* &prev)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    node* forward = curr->next;

    reverse1(head,forward,curr);
    curr->next = prev;

}


void solve1(node* &head)
{
    node* curr = head;
    node* prev = NULL;
    reverse1(head, curr, prev);
    print(head);

}

void reverse2(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        cout<<head->data<<endl;
        return;
    }

    reverse2(head->next);
    head->next->next = head;
    head->next = NULL;

    print(head);

}


int main()
{
    node* node1 = new node(10);
    node* head = node1;
    insertathead(head,15);
    insertathead(head,20);
    print(head);

    reverse(head);

    solve1(head);

    reverse2(head);
    
}
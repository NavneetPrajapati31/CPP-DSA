//approach 1 - with data replacement
//approach 2 - without data replacement


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
        // int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
       // cout<<"memory is free for node with data "<<value<<endl;

    }


};


void insertattail(node* &tail, int d)
{
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
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


void sortapp1(node* &head)
{
    node* temp = head;
    int count1 = 0;
    int count0 = 0;
    int count2 = 0;

    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            count0++;
        }

        else if(temp->data == 1)
        {
            count1++;
        }

        else if(temp->data == 2)
        {
            count2++;
        }

        temp = temp->next;

    }

    temp = head;


        while(count0!=0)
        {
            temp->data = 0;
            temp = temp->next;
            count0--;
        }

        while(count1!=0)
        {
            temp->data = 1;
            temp = temp->next;
            count1--;
        }

        while(count2!=0)
        {
            temp->data = 2;
            temp = temp->next;
            count2--;
        }

}


node* sortapp2(node* head)
{
    node* head0 = new node(-1);
    node* tail0 = head0;
    node* head1 = new node(-1);
    node* tail1 = head1;
    node* head2 = new node(-1);
    node* tail2 = head2;

    node* temp = head;
    
    while(temp != NULL)
    {
        int value = temp->data;

        if(value == 0)
        {
            insertattail(tail0,value);
        }

        else if(value == 1)
        {
            insertattail(tail1,value);
        }

        if(value == 2)
        {
            insertattail(tail2,value);
        }

        temp = temp->next;

    }

    if(head1->next != NULL)
    {
        tail0 ->next = head1->next;
    }

    else
    {
        tail0 -> next = head2->next;
    }

    tail1 ->next = head2->next;
    tail2 -> next = NULL;


    head = head0->next;

    delete head0;
    delete head1;
    delete head2;

    return head;

}



int main()
{
    node* node1 = new node(0);
    node* head = node1;
    node* tail = node1;

    print(head);
    insertattail(tail,2);
     print(head);
    insertattail(tail,1);
     print(head);
     insertattail(tail,2);
     print(head);
    insertattail(tail,1);
     print(head);

    //  sortapp1(head);
    //  print(head);

     head = sortapp2(head);
     print(head);
     

}
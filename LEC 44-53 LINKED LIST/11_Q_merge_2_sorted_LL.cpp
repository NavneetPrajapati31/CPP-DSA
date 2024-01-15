//Merge 2 sorted Linked List : https://bit.ly/3rfFdfV


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


node* solve(node* &first, node* &second)
{
    node* curr1 = first;
    node* next1 = curr1->next;
    node* curr2 = second;
    node* next2 = curr2->next;

    while(next1!=NULL && curr2 != NULL)
    {
        if((curr2->data= curr1->data) && (curr2->data<= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        
        }

        else
        {
            curr1 = next1;
            next1 = curr1->next;

            if(next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }

        }

    }

    return first;

}


node* mergesort(node* &head1,  node* &head2)
{
    node* ans = NULL;

    if(head1 == NULL)
    {
        return head2;
    }

    else if( head2 == NULL)
    {
        return head1;
    }

    if(head1->data >= head2->data)
    {
        ans = solve(head2,head1);
    }

    else if(head2->data >= head1->data)
    {
        ans = solve(head1,head2);
    }

    return ans;

}



int main()
{
    node* node1 = new node(2);
    node* node2 = new node(3);
    node* head1 = node1;
    node* tail1 = node1;
    node* head2 = node2;
    node* tail2 = node2;

    insertattail(tail1,4);
    insertattail(tail1,6);
    insertattail(tail2,5);
    insertattail(tail2,7);

    print(head1);
    print(head2);

    node* head = NULL;

    head = mergesort(head1, head2);
    print(head);
     
}
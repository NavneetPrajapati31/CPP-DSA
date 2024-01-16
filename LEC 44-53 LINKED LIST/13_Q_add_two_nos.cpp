//Add 2 Numbers rep. by Linked List: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbWNSQlpDcDdVWml2MklIVFQ3SEQyZWx1WXdsUXxBQ3Jtc0trNXBHMjQ1ZmI0UVYxb242TEFaUm40QVZkZ2tLSWNVa0R2S282NzR0TDN4SVV6aVN0TmVKYkFfdmppOXpvT0RGSFl5WmlucVZMTllDWmVBWS13RUhMazBBSFVvTEdzV2ZqQ3NnVjM2Yk1JU1dkcklKbw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fadd-two-numbers-represented-by-linked-lists%2F1&v=HiRlTPf9aCg


#include<iostream>
#include<vector>
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
        tail -> next = temp;
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


node* reverse(node* head)
{
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while(curr!= NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
        
    }
    
    return prev;

}


node* add(node* first, node* second)
{
    int carry = 0,sum,digit;

    node* anshead = NULL;
    node* anstail = NULL;

    while(first!= NULL || second!= NULL || carry!=0)
    {
        int val1 = 0;
        if(first!= NULL)
        {
            val1= first->data;
        }
        int val2;
        if(second!= NULL)
        {
            val2=second->data;
        }


        sum = carry + val1 + val2;
        carry = sum/10;
        digit = sum%10;

        insertattail(anshead,anstail,digit);
        if(first!=NULL)
        first = first->next;

        if(second!=NULL)
        second = second->next;
    }

    return anshead;

}

node* addition(node* first, node* second)
{
    first = reverse(first);
    second = reverse(second);

    node* ans = add(first, second);

    ans = reverse(ans);

    return ans;

}


int main()
{
    node* node1 = new node(2);
    node* head1 = node1;
    node* tail1 = node1;

    node* node2 = new node(6);
    node* head2 = node2;
    node* tail2 = node2;

    print(head1);
    print(head2);
    insertattail(head1,tail1,3);
    insertattail(head2,tail2,3);
     print(head1);
     print(head2);
    insertattail(head1,tail1,1);
    insertattail(head2,tail2,3);
     print(head1);
     print(head2);

     node* ans = addition(head1,head2);

     print(ans);
    
}
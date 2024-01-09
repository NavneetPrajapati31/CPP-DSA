/*middle of a Linked List: https://bit.ly/3H1lKov
approach 1 using length of ll
approach 2 
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

int getlength(node* head)
{
    int len=0;
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        len++;    
    }

    return len;
}

node* findmiddle1(node* &head)
{
    int len = getlength(head);
    int ans= len/2 +1;
    int cnt = 1;

    node* temp = head;

    while(cnt < ans)
    {
        cnt++;
        temp = temp->next;
    }

return temp;

}

node* findmiddle2(node* &head)
{   
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node* slow = head;
    node* fast = head->next;

    while(fast!= NULL)
    {
        fast = fast->next;
        if(fast!= NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }

return slow;

}


int main()
{
    node* node1 = new node(10);
    node* head = node1;
    insertathead(head,15);
    insertathead(head,20);
    insertathead(head,25);
    insertathead(head,30);

    print(head);

    cout<<getlength(head)<<endl;
    cout<<findmiddle1(head)->data<<endl;
    cout<<findmiddle2(head)->data;


}
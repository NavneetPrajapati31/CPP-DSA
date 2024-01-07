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

//insertion at head

void insertathead(node* &head, int d)
{
    node* temp = new node(d);
    temp -> next = head;
    head = temp  ;
}

//insertion at tail

void insertattail(node* &tail, int d)
{
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
}


//insertion in middle

void insertmiddle(node* &head, node* &tail, int position, int d)
{

    if(position == 1)
    {
        insertathead(head,d);
        return;
    }

    node* temp = head;
    int cnt=1;

    while(cnt < position-1)
    {
        cnt++;
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        insertattail(tail,d);
        return;
    }

    node* nodetobeinserted = new node(d);

    nodetobeinserted -> next = temp -> next;
    temp -> next = nodetobeinserted;

    

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


void deletenode(node* &head, int position)
{
    if(position == 1)
    {
        node* temp = head;
        temp = temp->next;

        //delete
        temp->next = NULL;
        delete temp;

    }

    else
    {
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            cnt++;
            prev=curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }

}


int main()
{
    node* node1 = new node(10);

    cout<<node1 -> data <<endl;
    cout<<node1 -> next <<endl;

    node* head = node1;
    node* tail = node1;
    
    insertathead(head,12);
    print(head);

    insertattail(tail,15);
    print(head);

    insertmiddle(head,tail,4,8);
    print(head);

    deletenode(head,3);
    print(head);
 

    return 0;

}
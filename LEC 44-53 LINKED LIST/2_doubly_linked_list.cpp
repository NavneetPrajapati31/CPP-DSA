#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* prev;
    node* next;

    //constructor

    node(int d)
    {
        this-> data = d;
        this-> prev = NULL;
        this->next = NULL;

    }

    //DESTRUCTOR

    ~node()
    {
        int val = this -> data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
 
        cout<<"memory is free or node with data "<<val<<endl;

    }

};

void print(node* head)
{
    node* temp = head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

}

int getlength(node* head)
{
    node* temp = head;
    int len=0;
    while(temp!= NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;

}

void insertathead(node* &head, node* &tail, int d)
{
    if(head == NULL)
    {
        node* temp = new node(d);
        head = temp;
        tail = temp;

    }

    else
   {
    node* temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;

   }
    

}

void insertattail(node* &head, node* &tail, int d)
{
    if(head == NULL)
    {
        node* temp = new node(d);
        head = temp;
        tail = temp;
        
    }
    else
    {
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;

    }

}

void insertatposition(node* &head, node* &tail, int position, int d)
{
    if(position == 1)
    {
        insertathead(head,tail,d);
        return;
    }

    node* temp = head;
    int cnt=1;

    while(cnt < position-1)
    {
        cnt++;
        temp = temp->next;
    }

    if(temp -> next == NULL)
    {
        insertattail(head,tail,d);
        return;
    }

    node* nodetoinsert = new node(d);

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;

}

void deletenode(node* &head, node* &tail, int position)
{
    if(position == 1)
    {
        node* temp = head;
        head = head->next;
        head->prev = NULL;

        temp->next = NULL;
        delete temp;

    }

    else
    {
        node* curr = head;
        node* pre = NULL;
        int cnt = 1;

        while(cnt<position)
        {
            cnt++;
            pre = curr;
            curr = curr->next;

        }

        if(curr->next != NULL)
        {
        pre -> next = curr -> next;
        curr ->next->prev = pre;
        curr->next = NULL;
        delete curr;

        }

        else
        {
        pre->next = NULL;
        tail = pre;
        curr->next = NULL;
        delete curr;

        }

    }

}


int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    print(head);
    cout<<getlength(head)<<endl;

    insertathead(head,tail,12);
    print(head);

    insertathead(head,tail,14);
    print(head);

    insertathead(head,tail,16);
    print(head);

    insertattail(head,tail,8);
    print(head);

    insertatposition(head,tail,6,5);
    print(head);

    deletenode(head,tail,6);
    print(head);

    cout<<head->data<<endl;
    cout<<tail->data<<endl;

}
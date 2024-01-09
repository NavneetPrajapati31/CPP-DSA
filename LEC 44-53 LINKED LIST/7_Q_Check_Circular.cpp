// Circular Linked List or not: https://bit.ly/3qY0KcF

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

    ~node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertnode(node* &tail, int element, int d)
{
    //empty list

    if(tail == NULL)
    {
        node* temp = new node(d);
        tail = temp;
        temp -> next = temp;
    }

    //non empty list

    else
    {
        node* curr = tail;

        while(curr->data != element)
        {
            curr = curr->next;
        }

        node* nodeinsert = new node(d);

        nodeinsert->next = curr->next;
        curr -> next = nodeinsert;

    }
}

void printnode(node* tail)
{
    node* temp = tail;

    if(tail == NULL)
    {
        cout<<"empty list"<<endl;
        return;
    }

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;

    }

    while(tail != temp);

    cout<<endl;
}

void deletenode(node* tail, int value)
{
    if(tail == NULL)
    {
        cout<<"empty list check again";
        return;
    }

    else
    {

        node* prev = tail;
        node* curr = prev->next;

        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 node linked list

        if(curr == prev)
        {
            tail = NULL;
        }

        //>=2 node linked list

        else if(tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;

    }

}

bool iscircular(node* head)
{
    if(head == NULL)
    {
        return true;
    }

    node* temp = head->next;

    while(temp!= NULL && temp!= head)
    {
        temp = temp->next;
    }

    if(temp == head)
    {
        return true;
    }

    return false;

}


int main()
{
    node* tail = NULL;
    insertnode(tail,5,5);
    printnode(tail); 

    insertnode(tail,5,6);
    printnode(tail); 

    insertnode(tail,6,7);
    printnode(tail);

    insertnode(tail,7,8);
    printnode(tail); 

    insertnode(tail,8,9);
    printnode(tail); 

    /*deletenode(tail, 5);
    printnode(tail);*/

    if(iscircular(tail))
    {
        cout<<"yes"<<endl;
    }

    else
    {
        cout<<"no"<<endl;
    }


}
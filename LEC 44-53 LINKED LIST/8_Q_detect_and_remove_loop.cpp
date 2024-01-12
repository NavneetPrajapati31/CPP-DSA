//Detect & Remove Loop in Linked List: https://bit.ly/3rSdTDo

//detect loop using map

//floyd's cycle detection

//starting node of loop

//delete loop

#include<iostream>
#include<map>
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

void insertathead(node* &head, int d)
{
    node* temp = new node(d);
    temp -> next = head;
    head = temp  ;
}


void insertattail(node* &tail, int d)
{
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
}


void insertatposition(node* &head, node* &tail, int position, int d)
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

    if(temp -> next == NULL)
    {
        insertattail(tail,d);
        return;
    }

    node* nodetoinsert = new node(d);

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;

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

bool detectloop(node* head)
{
    if(head == NULL)
    {
        return false;
    }

    map<node*, bool> visited;

    node* temp = head;

    while(temp != NULL)
    {

        if(visited[temp] == true)
    {
        return true;
    }

        visited[temp] = true;
        temp = temp->next;

    }

    return false;
    
}

//floyd's cycle detection

node* floydcycledetection(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while(fast != NULL && slow != NULL)
    {
        fast = fast->next;
        
        while(fast != NULL)
        {
            fast = fast -> next;
        }

        slow=slow->next;

        if(slow == fast)
        {
            cout<<"present at "<< slow->data<<endl;
            return slow;
        }
        
    }

return NULL;

}


node* startingnode(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    node* slow = head;
    node* intersection = floydcycledetection(head); 

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void deleteloop(node* head)
{
    node* temp = head;
    node* start = startingnode(head);

    while(temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = NULL;

}


int main()
{
    node* node1 = new node(5);
    node*head = node1;
    node* tail = node1;
    
    // printnode(tail); 

    insertattail(tail,12);
    // printnode(tail); 

    insertattail(tail,15);
    // printnode(tail);

    insertatposition(head,tail,4,22);

    tail ->next = head->next;
    cout<<head->data<<endl;
    cout<<tail->data<<endl;

    if(floydcycledetection(head) != NULL)
    {
        cout<<"loop present"<<endl;
    }

    else
    {
        cout<<"loop not present"<<endl;
    }

    cout<<startingnode(head)->data;

    deleteloop(head);
    printnode(head);

}


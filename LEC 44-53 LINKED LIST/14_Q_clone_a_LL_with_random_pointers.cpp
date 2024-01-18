//Clone Linked List with Random Pointers: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbld0amZBR3V6QTMteUJvc3FSbmJyZ0h0QnJSUXxBQ3Jtc0tsdFJON1NkMW4xeVFVdmM4cnBSX1ZlaVctSFktc0hFcUlUTXVUUjIxNDd5S3BpYUtaclBJcHJ2ak9YWFJkMllXQzQ2QjlhWk5CYXNsdW43RmducnU3VGpwWkdDYktFWm81QklFZnJKMkt6QnVoNi1tSQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fclone-a-linked-list-with-next-and-random-pointer%2F1&v=83mPr0i56Gg

//approach 1 - T.C. = O(n^2)
//approach 2 - MAPPING T.C. = O(n), S.C. = O(n)
//approach 3 - CHANGING LINKS T.C. = O(n), S.C. = O(1)

#include<iostream>
#include<map>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    node* random;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
        tail->next= temp;
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


node* clone1(node* &head)
{
    node* temp1 = head;
    node* clonehead = NULL;
    node* clonetail = NULL;

    while(temp1!= NULL)
    {
        insertattail(clonehead,clonetail,temp1->data);
        temp1 = temp1->next;
    }

    node* clonetemp1 = clonehead;
    node* cloneclonenode = clonehead;
    temp1 = head;
    node* clonenode = head;
    node* random = NULL;

    while(temp1!= NULL)
    {
        random = temp1->random;
        clonenode = head;
        cloneclonenode = clonehead;
        while(clonenode != random)
        {
            clonenode = clonenode->next;
            cloneclonenode = cloneclonenode->next;
        }
clonetemp1->random = cloneclonenode;
clonetemp1 = clonetemp1->next;
temp1 = temp1->next;

    }

return clonehead;

}


node* clone2(node* &head)
{
    //step-1 create a clone list

    node* clonehead = NULL;
    node* clonetail = NULL;
    node* temp = head;

    while(temp != NULL)
    {
        insertattail(clonehead,clonetail,temp->data);
        temp = temp->next;

    }

    //step-2 create a map

    map<node*, node*> oldtonewnode;

    node* originalnode = head;
    node* clonenode = clonehead;
    while(temp!= NULL)
    {
        oldtonewnode[originalnode] = clonenode;
        originalnode = originalnode->next;
        clonenode = clonenode->next;
    }

    originalnode = head;
    clonenode = clonehead;

    //step-3 linking randoms

    while(originalnode!= NULL)
    {
        clonenode->random = oldtonewnode[originalnode->random];
        originalnode = originalnode->next;
        clonenode = clonenode->next;
    }

    return clonehead;
    
}


node* clone3(node* &head)
{
    //step-1 create a clone list

    node* clonehead = NULL;
    node* clonetail = NULL;
    node* temp = head;

    while(temp != NULL)
    {
        insertattail(clonehead,clonetail,temp->data);
        temp = temp->next;

    }

    //step-2 add clonenodes between original nodes

    node* originalnode = head;
    node* clonenode = clonehead;

    while(originalnode!= NULL)
    {
        node* next = originalnode->next;
        originalnode->next = clonenode;
        originalnode = next;

        next = clonenode->next;
        clonenode->next = originalnode;
        clonenode = next;

    }

    //step-3 copy random pointer

    temp = head;

    while(temp != NULL)
    {
        if(temp->next!= NULL)
        {
            temp->next->random = temp->random ? temp->random->next: temp->random;
        }

        temp = temp->next->next;

    } 

    //step-4 revert changes done in step-2

    originalnode = head;
    clonenode = clonehead;

    while(originalnode!= NULL)
    {
        originalnode->next = clonenode->next;
        originalnode = originalnode->next;

        if(originalnode!= NULL)
        {
            clonenode->next = originalnode->next;
        }

        clonenode = clonenode->next; 
        
    }

    //step-5 return ans;

    return clonehead;

}


int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertattail(head,tail,15);
    print(head);
    insertattail(head,tail,20);
    print(head);

    node* clonenode = clone3(head);
    cout<<"cloned list"<<endl;
    print(clonenode);
    
}
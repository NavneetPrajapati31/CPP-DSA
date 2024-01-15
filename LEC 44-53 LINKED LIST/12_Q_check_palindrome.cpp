//Palindrome Linked List: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbGNzVDhMS3BwSXZnc0FiWExvTlFwMnZqZjV6Z3xBQ3Jtc0trb0hacDQ4Y3czUkVEamlXQUVaN2hJbHBaSlpzZVpVWXd6SXNtVTFqNThkOEp5d0RHc3o5UHJlYkVMNE9aWW9ZSXF2alJLdGVpM0lrNVRieExLN0ZwUXhlOEViLU5LSXhtRmw3ckhqRlBrUmpsMUZyVQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fcheck-if-linked-list-is-pallindrome%2F1%2F&v=aD7mBVnKFEU

//approach 1 - creating vector array, S.C. = O(n)
//approach 2 - finding middle and comparing, S.C. = O(1)


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


//approach 1


bool checkpalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s<=e)
    {
        if(arr[s] != arr[e])
        {
            return false;
        }

        s++;
        e--;
    }

    return true;

}

bool ispalindrome(node* head)
{
    vector<int> arr;
    node* temp = head;
    while(temp!= NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkpalindrome(arr);

}

node* findmid(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast!= NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;

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


//approach 2


bool check(node* head)
{
    if(head->next == NULL)
    {
        return true;
    }

    node* middle = findmid(head);

    node* temp = middle->next;
    middle -> next = reverse(temp);

    node* head1 = head;
    node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1->data != head2->data)
        {
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;

    }

    temp = middle->next;
    middle -> next = reverse(temp);

    return true;
}


int main()
{
    node* node1 = new node(2);
    node* head = node1;
    node* tail = node1;

    print(head);
    insertattail(tail,3);
     print(head);
    insertattail(tail,1);
     print(head);
    insertattail(tail,1);
     print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,2);
    print(head);

    if(ispalindrome(head))
    {
        cout<<"yes"<<endl;
    }

    else
    {
        cout<<"no"<<endl;
    }


    if(check(head))
    {
        cout<<"yes"<<endl;
    }

    else
    {
        cout<<"no"<<endl;
    }

}
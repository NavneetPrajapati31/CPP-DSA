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
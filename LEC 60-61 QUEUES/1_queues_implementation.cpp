//Queue Implementation : https://bit.ly/3uL7QDG
//implementing queue using arrays

#include<iostream>
#include<queue>
using namespace std;


class Queue {

    public:

    int *arr;
    int front;
    int rear;
    int size;
    

    Queue(int size) 
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {

        if(front == rear)
        {
            return true;
        }
        
        else
        
        return false;
    }

    void enqueue(int data) {
        
        if(rear == size)
        {
            cout<<"queue is full"<<endl;
        }

        else
        {
            arr[rear] = data;
            rear++;
        }

    }

    int dequeue() {
        if(front == rear)
        {
            return -1;
        }

        else
        {
            int val = arr[front];
            arr[front] = -1;
            front++;
            return val;
        }

        
        
    }

    int front() {
        if(front == rear)
        {
            return -1;
        }

        else
        {
            return arr[front];
        }
    
    }
};
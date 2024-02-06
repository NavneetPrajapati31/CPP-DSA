//Queue Implementation : https://bit.ly/3uL7QDG
//implementing queue using arrays

#include<iostream>
#include<queue>
using namespace std;


class Queue {

    public:

    int *arr;
    int qfront;
    int rear;
    int size;
    

    Queue() 
    {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {

        if(qfront == rear)
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
        if(qfront == rear)
        {
            return -1;
        }

        else
        {
            int val = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            return val;
        }

        
        
    }

    int front() {
        if(qfront == rear)
        {
            return -1;
        }

        else
        {
            return arr[qfront];
        }
    
    }
};
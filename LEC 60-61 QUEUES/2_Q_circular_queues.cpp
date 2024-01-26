//Circular Queue : https://bit.ly/34xocVZ


class CircularQueue{
    public:

    int front;
    int rear;
    int* arr;
    int size;

   
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
       
    }

    
    bool enqueue(int value)
    {

        if((front == 0 && rear == size-1) || (rear == (front-1)))
        {
            return false;
        }


        else if(front == -1)
        {
            front = 0;
            rear = 0;
        }

        else if(rear==size-1 && front!=0)
        {
            rear = 0;
        }

        else
        {
            rear++;   
        }

        arr[rear] = value;
        return true;
       
    }

    
    int dequeue()
    {
        if(front == -1)
        {
            return -1;
        }

        int ans = arr[front];

        if(front == rear)
        {
            front = rear = -1;
        }

        else if(front == size-1)
        {
            front = 0;
        }

        else
        {
            front++;
        }

        return ans;
       
    }
};
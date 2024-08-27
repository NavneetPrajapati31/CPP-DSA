#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent] , arr[index]);
                index = parent;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }

    void deleteNode()
    {
        if(size == 0)
        {
            cout<<"nothing to delete";
        }

        //change value of first element

        arr[1] = arr[size];

        //remove last element

        size--;

        //check for root node and take it to its correct posiiton;

        int i = 1;

        while(i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(arr[i] < arr[leftIndex] && leftIndex < size)
            {
                swap(arr[i] , arr[leftIndex]);
                i = leftIndex;
            }

            else if(arr[i] < arr[rightIndex] && rightIndex < size)
            {
                swap(arr[i] , arr[rightIndex]);
                i = rightIndex;
            }

            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest] , arr[i]);
        heapify(arr,n,largest);
    }
}

int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);

    h.print();

    h.deleteNode();

    h.print();

    int arr[6] = {-1,6,7,8,9,10};
    int n = 5;

    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
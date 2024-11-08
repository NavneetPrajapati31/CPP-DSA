#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[50];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int d)
    {
        size = size+1;
        int index = size;
        arr[index] = d;

        while(index>1)
        {
            int parent = index/2;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
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
    }

    void deleteroot()
{
    if(size == 0)
    {
        return;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    
    while(i< size)
    {
        int right = 2*i +1;
        int left = 2*i;

        if(arr[left] > arr[i] && left<=size)
        {
            swap(arr[left] , arr[i]);
            i = left;
        }

        if(arr[right] > arr[i] && right<=size)
        {
            swap(arr[right] , arr[i]);
            i = right;
        }

        else
        return;
    }
}

};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int right = 2*i +1;
    int left = 2*i;

    if(left<=n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right<=n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[] ,int n)
{
    int size = n;
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
}

int main()
{
    heap h;
    h.insert(53);
    h.insert(55);
    h.insert(50);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteroot();

    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
        for(int i=n/2;i>0;i--)
        {
        heapify(arr,n,i);
        }

        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;

        heapsort(arr,n);

        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
}
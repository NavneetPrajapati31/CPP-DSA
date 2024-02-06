//Bubble Sort : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmxLblljc3VmQy1WT2RIUmktNEFIN3lnRkxPZ3xBQ3Jtc0ttUko5NXowVG1JUldDOEFUSnpBUHF3U3hWMFozakhRVVZ4dlRaaXo2R2psOTVGUVd1blhRY096ZEQ3ZjFucjRZQkZPOU9NN2d4d3pOZDZTY0JlS0NSb1k1Q3pKVFF5R29vX3p5bWZZci1XS3J5VVhaUQ&q=https%3A%2F%2Fbit.ly%2F3pvCTz9&v=zOhUavxlzw4


#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int> arr,int n)
{
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}

void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
    }
}


int main()
{
     int n,element;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr.push_back(element);
    }

    bubbleSort(arr,n);
    printarr(arr,n);

   return 0;
}
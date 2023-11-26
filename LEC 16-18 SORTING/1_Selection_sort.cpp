//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbm5OWHJ6SVlTN3BzWS1WNXd4T3czVWpNcy1HQXxBQ3Jtc0ttWWxrTHFJc3pUMTBmS2NFdVgyY2FROHJnWG5IdXZLNmRIUmVYUS1HZlhsd0NVSGxjWVotMTg2dGp1a19sUjY2S19oa0ZRV2lhM0tqWGxJMDZvcHgyVElobkJqcGZYUTBMSV9OVnJ1Rk9YOFlNakhocw&q=https%3A%2F%2Fbit.ly%2F3DrsGsv&v=UdO2NeHB46c



#include<iostream>
#include<vector>
using namespace std;

void printvector(vector<int> v)
{
    for(int i:v)
    {
        cout<< i <<" ";
    }
}

void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
        6
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

    selectionSort(arr,n);
    printvector(arr);

   return 0;
}
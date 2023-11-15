#include<iostream>
#include<vector>

using namespace std;


    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            
            int element = matrix[mid/col][mid%col];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }


int main()
{
    vector<vector<int>> arr;

    //taking input -> row wise input
    for(int row=0; row<3; row++)
     {
        for(int col=0; col<3; col++)
        {
            cin >> arr[row][col];
        }
    }

    int target;
    cin>>target;

    cout<<searchMatrix(arr,target);

}
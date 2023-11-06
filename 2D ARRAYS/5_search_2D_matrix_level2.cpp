#include<iostream>
#include<vector>

using namespace std;


    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex < row && colIndex>=0 ) {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target){
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
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
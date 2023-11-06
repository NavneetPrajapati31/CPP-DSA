#include<iostream>
using namespace std;

//LINEAR SEARCH IN 2D ARRAY
bool isPresent(int arr[][3], int target, int row, int col) {

  for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            
            if( arr[row][col] == target) {
                return 1;
            }
            
        }
    }
    return 0;
}

//to print column wise sum
void printColSum(int arr[][3], int row, int col) {
    cout << "Printing Sum -> " << endl;
    for(int col=0; col<3; col++) {
        int sum = 0;
        for(int row=0; row<3; row++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}


//to print row wise sum
void printrowSum(int arr[][3], int row, int col) {
    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}

int largestRowSum(int arr[][3], int row, int col) {

    int maxi = INT32_MIN;
    int rowIndex = -1;

    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }

        if(sum > maxi ) {
            maxi = sum;
            rowIndex = row;
        }
       
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}



int main()
{
    int arr[3][3];

    cout << "Enter the elements " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++)
     {
        for(int col=0; col<3; col++)
        {
            cin >> arr[row][col];
        }
    }

/*
//taking input -> col wise input
    for(int col=0; col<4; col++) 
    {
        for(int row=0; row<3; row++) 
        {
            cin >> arr[row][col];
        }
    }
*/

cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
        cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    /*
    cout <<" Enter the element to search " << endl;
    int target;
    cin >> target;

    if(isPresent(arr, target, 3, 3)) {
        cout <<" Element found " << endl;
    }
    else{
        cout <<" Not Found" << endl;
    }

    printColSum(arr, 3, 3 );
    */
   int ansIndex = largestRowSum(arr,3,3);
   cout << " Max row is at index " << ansIndex << endl;
    
}
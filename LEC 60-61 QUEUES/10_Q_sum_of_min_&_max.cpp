//Sum of min & max elements of all subarray of size K : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbHpqSFdrSVBOa2dlbVRBaWZOeFE1MnNqWndWUXxBQ3Jtc0trR08yT1hScWQxTVZ6RFNBQmRmRUdwU1hPNWwxVkRmX0lKd09IYW5ScWZyZV9uRFByQzNEVmNUMnlUb0dvRnBjUVBPbC1XY2syZWtYb2gtLUllc0FUSnJTdEQxMmxVQjBIMU4zUHJJYmFvOGt0VjRqNA&q=https%3A%2F%2Fwww.geeksforgeeks.org%2Fsum-minimum-maximum-elements-subarrays-size-k%2F&v=_gJ3to4RyeQ


#include<iostream>
#include<queue>
using namespace std;


int solve(int* arr, int n, int k)
{
    deque<int> maxi;
    deque<int> mini;

    for(int i=0; i<k; i++)
    {
        while(arr[maxi.back() <= arr[i]] )
        {
            maxi.pop_back();
        }

        while(arr[mini.back() >= arr[i]] )
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        int ans=0;

        for(int i=k;i<n;i++)
        {
            ans = arr[maxi.front()] + arr[mini.front()];
            //next window

            //removal and addition

            while(!maxi.empty() && i - maxi.front() >= k)
            {
                maxi.pop_back();
            }

            while(!mini.empty() && i - mini.front() >= k)
            {
                mini.pop_back();
            }


             while(!maxi.empty() && arr[maxi.back() <= arr[i]] )
        {
            maxi.pop_back();
        }

        while(arr[!mini.empty() && mini.back() >= arr[i]] )
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        }

        //last waali window

        ans = arr[maxi.front()] + arr[mini.front()];
        return ans;
        
    }


}
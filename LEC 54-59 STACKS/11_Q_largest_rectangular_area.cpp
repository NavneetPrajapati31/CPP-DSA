//Largest Rectangular Area in Histogram:https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTQyQTZiaFFlWEwzMElMakloLVRNcTU3VzhYZ3xBQ3Jtc0ttVnVnQzZSbF84dENVZUtwUVlyWkxNZ1FfMkIwUUxmRUR6TnNGam4wYzBmMUlvZ0huaWQyRVRMOG9BdUw4MXFpZ0xOV3l0WEdUcXNsSG5vbHNLR0pheE5BMUJBeEZHV212SXFaM3pibllidWlacmQwWQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Flargest-rectangle-in-histogram%2F&v=lJLcqDsmYfg


#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top()!= -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=0; i<n ; i++) {
        int curr = arr[i];
        while(s.top()!= -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int largestarea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = INT64_MIN;

    for(int i = 0; i<n; i++)
    {
        int l = heights[i];
        
        if(next[i] == -1)
        {
            next[i] == n;
        }

        int b = next[i] - prev[i] - 1;

        int newarea = l*b;

        area = max(area, newarea);
    }

    return area;

}

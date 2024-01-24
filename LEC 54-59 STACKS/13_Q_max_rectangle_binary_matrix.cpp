//Max Rectangle in Binary Matrix with all 1's : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbjAyVXJXT0Nka29rbWdVcV9LZzFmSWtZOFBOUXxBQ3Jtc0tucVZTYTRBWVQtaUs1ZExVWjlZajQwVTBHSkRKQjVmaXYxQ1RXS0hyQzZTQ0xpR2VGOG04Y1ExWmZ6TXVMQUlBQVkzSkEyNjc2c3JNUkR0Und2X2plMVlKZzlKZVprTUdBQTlHRHhhTEUyM0dWMXR2Yw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fmax-rectangle%2F1%2F&v=9u2BJfmWNEg

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MAX 1000


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


int largestarea(vector<int> &heights, int n)
{
    // int n = heights.size();

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


int maxArea(int M[MAX][MAX], int n, int m)
{
    //calculate area for first row

    int area = largestarea(M[0], m);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j] != 0)
            {
             M[i][j] = M[i][j] + M[i-1][j];
            }

            else
            M[i][j] = 0;
        }

        int newarea = largestarea(M[i], m);
        area = max(area,newarea);
    }

    return area;

}
//Celebrity Problem : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbm11U0ZHU3N6d0pOakgyVHZvNU1JOF9jMWFZUXxBQ3Jtc0tsek9kTENNQU1tU0hrT0VESHZPWWZJQmZ6bFpzNmVrckNBc2VfOXZaZ0Z1OFRDWnlCQWlxQ2FyYUlRUzVnX0VfLW9RcENwZlZiVmpyV3pVT3hyaDFfRUlYQThYUXFxaERVZzE1MXlBSDQyUk53S19wSQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fthe-celebrity-problem%2F1%2F&v=9u2BJfmWNEg

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


bool knows(vector<vector<int>> M, int a, int b, int n)
{
    if(M[a][b] == 1)
    {
        return true;
    }

    else
    return false;

}

int celeb(vector<vector<int>> M, int n)
{
    //step 1 push all elements in stack

    stack<int> s;
    for(int i=0; i<n; i++)
    {
        s.push(i);
    }

    //step 2 get 2 elements and compare them

    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b,n) == 1)
        {
            s.push(b);
        }

        else
        {
            s.push(a);
        }
    }

    
    //step 3 single element is potential celeb

    int ans = s.top();
    bool rowcheck = false;
    int zerocnt=0;
    for(int i=0;i<n;i++)
    {
        if(M[ans][i] == 0)
        {
            zerocnt++;
        }
    }

    if(zerocnt == n)
    {
        rowcheck = true;
    }

    bool colcheck = false;
    int onecnt = 0;

    for(int i=0;i<n;i++)
    {
        if(M[i][ans] == 1)
        {
            onecnt++;
        }
    }

    if(onecnt == n-1)
    {
        colcheck = true;
    }

    if(rowcheck == true && colcheck == true)
    {
        return ans;
    }

    else

    return -1;

}



//optimised solution



int celeb_(vector<vector<int>> M, int n)
{
    //step 1 push all elements in stack

    stack<int> s;
    for(int i=0; i<n; i++)
    {
        s.push(i);
    }

    //step 2 get 2 elements and compare them

    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b,n) == 1)
        {
            s.push(b);
        }

        else
        {
            s.push(a);
        }
    }

    
    //step 3 single element is potential celeb

    int ans = s.top();
    
    int zerocnt=0;
    for(int i=0;i<n;i++)
    {
        if(M[ans][i] == 0)
        {
            zerocnt++;
        }
    }

    if(zerocnt != n)
    {
        return -1;
    }

    
    int onecnt = 0;

    for(int i=0;i<n;i++)
    {
        if(M[i][ans] == 1)
        {
            onecnt++;
        }
    }

    if(onecnt != n-1)
    {
        return -1;
    }

    return ans;

}
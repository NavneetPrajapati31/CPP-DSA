//Delete Middle Element in Stack:https://bit.ly/3ovTIu2


#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> s, int count, int N)
{
    //base case
    if(count == N/2)
    {
        s.pop();
        return;
    } 

    int ans = s.top();
    s.pop();
    solve(s,count+1,N);
    s.push(ans);
    
}

void deletemiddle(stack<int> s, int N)
{
    int count=0;
    solve(s,count,N);
}

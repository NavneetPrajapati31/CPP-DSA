//InsertAtBottom in Stack:https://bit.ly/34qqmGL


#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int> &s, int element)
{
    //base case
    if(s.empty())
    {
        s.push(element);
        return;
    }

        char ch = s.top();
        s.pop();

        solve(s,element);
        s.push(ch);

}


stack<int> insert(stack<int> &s, int x)
{
    solve(s,x);
    return s;

}
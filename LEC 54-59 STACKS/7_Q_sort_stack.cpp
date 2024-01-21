//Sort a Stack using recursion:https://bit.ly/3snpr1B
#include<iostream>
#include<stack>
using namespace std;


void sortinsert(stack<int> &stack, int element)
{
    if(stack.empty() || (!stack.empty() && stack.top()<element))
    {
        stack.push(element);
        return;
    }

    int num = stack.top();
    stack.pop();

    sortinsert(stack,element);

    stack.push(num);
}

void sortstack(stack<int> &s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    sortstack(s);

    sortinsert(s,num);

}
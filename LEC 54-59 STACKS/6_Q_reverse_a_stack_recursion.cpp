//Reverse a Stack using recursion:https://bit.ly/3HCBnD4
#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s, int element)
{
    //base case
    if(s.empty())
    {
        s.push(element);
        return;
    }

        int num = s.top();
        s.pop();

        insert(s,element);
        s.push(num);

}


void reverse(stack<int> &s)
{
   //base case
   if(s.empty())
   {
    return;
   }

   int num = s.top();
   s.pop();

   reverse(s);

   insert(s,num);

}
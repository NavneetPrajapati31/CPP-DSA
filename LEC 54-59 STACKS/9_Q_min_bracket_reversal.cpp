//Minimum bracket Reversal:https://bit.ly/3GAYRr5


#include<iostream>
#include<stack>
#include<string>
using namespace std;


int findMinimumCost(string str)
{
    stack<char> st;

    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];

        if(ch == '{')
        {
            st.push(ch);
        } 

        else
        {
            //ch is closing bracket

            if((!st.empty()) && st.top() == '{')
            {
                st.pop();
            }

            else
            {
                st.push(ch);
            }
        }
    }

    //stack contains invalid expression
    int a=0,b=0;
    while(!st.empty())
    {
        if(st.top() == '(')
        {
            b++;
        }

        else
        {
            a++;
        }
        st.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;

}

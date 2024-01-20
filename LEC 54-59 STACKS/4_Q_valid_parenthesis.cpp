//Valid Parenthesis:https://bit.ly/34kxPaq


#include<string>
#include<stack>
using namespace std;

bool isvalid(string expression)
{
    stack<char> s;
    for(int i=0; i<expression.length(); i++)
    {
        char ch = expression[i];

        //opening brackets

        if(ch == '(' || ch =='{' || ch =='[' )
        {
            s.push(ch);
        }

        else
        {
            //closing brackets
            if(!s.empty())
            {
                if((s.top()=='(' && ch ==')') || (s.top()=='{' && ch =='}') || (s.top()=='[' && ch ==']'))
                {
                    s.pop();
                }

                else
                {
                    return false;
                }

            }

            else
            {
                return false;
            }

        }

    }

    if(s.empty())
    {
        return true;
    }

    else
    return false;
    
}
//Special Stack: https://bit.ly/3LpVPJM


#include<stack>
#include<iostream>
using namespace std;

class SpecialStack {
    public:
    stack<int> s;
    int mini;
        
    void push(int data) {

        if(s.empty())
        {
            s.push(data);
            mini = data;
        }

        else
        {
            if(data<mini)
            {
                s.push(2*data - mini);
                mini = data;
            }

            else
            {
                s.push(data);
            }

        }

    }


    int pop() {

        if(s.empty())
        {
            return -1;
        } 

        int curr = s.top();
        s.pop();

        if(curr > mini)
        {
            return curr;
        }

        else
        {
            int prevmin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevmin;
        }

    }


    int top() {
        if(s.empty())
        return -1;

        int curr = s.top();

        if(curr<mini)
        {
            return mini;
        }

        else
        {
            return curr;
        }

        
    }
    

    int getMin() {
         if(s.empty())
        return -1;

        return mini;
        
    }  
};
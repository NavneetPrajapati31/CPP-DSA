#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str = "navneet";
    stack<char> s;

    for(int i = 0; i<str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty())
    {
        char val = s.top();
        ans.push_back(val);
        s.pop();
    }

    cout<<"answer is "<<ans<<endl;

    return 0;
}


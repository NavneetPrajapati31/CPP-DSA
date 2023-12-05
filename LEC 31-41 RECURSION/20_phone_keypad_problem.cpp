//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqblQ1bzdIODRqdURvOFBLdFhMNEU5Z0dvczE1QXxBQ3Jtc0tsSm16WGs2NjRaamVERG5XeE40bDFnUmhvTkN1TF9mRGMyMjdYLTBYQXk3TU9KT3pqWFM2VzhRWXlMYTBHMnpFbF9fM0czc0pLUGRTVmpZcUZvSGpwZGRraTVqa0hzaG9ldVdXRXpScXhTNzZ4X3hOTQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fletter-combinations-of-a-phone-number%2F&v=tWnHbSHwNmA


#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(string digits, int index, string output, vector<string> ans,string mapping[])
{

    if(index>digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number=digits[index]-'0';
    string value=mapping[number];

    for(int i=0;i<value.length();i++)
    {
        output.push_back(value[i]);
        solve(digits,index+1,output,ans,mapping);
        output.pop_back();

    }

}

vector<string> keypad(string digits)
{
    vector<string> ans;
    if(digits.length()==0)
    {
        return ans;
    }

    string output="";

    int index=0;

    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(digits,index,output,ans,mapping);
    return ans;

}

int main()
{
    string digits;
    cin>>digits;

    keypad(digits);

}
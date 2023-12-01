#include<iostream>
using namespace std;

bool palindrome(string s,int i,int j)
{
    if(i>j)
    {
        return false;
    }

    if(s[i]==s[j])
    {
        return true;
        i++;
        j--;
    }

    else
    {
        return false;
    }
   
palindrome(s,i,j);

}

 int main()
 {
    string name = "teeneet";
    cout<<palindrome(name,0,name.length()-1);
    
 }
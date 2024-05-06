#include<iostream>
#include<string>
using namespace std;

void reverse(string& st,int s,int e)
{
    while(s<=e)
    {
        swap(st[s++],st[e--]);
    }

}
void reversewords(string &s,int n)
{
    //my name
    int i=0;
    int j=0;
    while(i<n && j<n)
    {
        while((s[j]!=' ' && s[j]!='\0') && j<n)
    {
        j++;
    }

   
    reverse(s,i,j-1);
    j++;
    i=j;
    }

}

int main()
{
    char s[50];
    cin.getline(s,50);

    string st;
    for(int i=0;s[i]!='\0';i++)
    {
        st.push_back(s[i]);
    }
    reversewords(st,st.length());
    cout<<st;
    
}
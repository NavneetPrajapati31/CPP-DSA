#include<iostream>
#include<string>

using namespace std;

void reverse(string &s,int i,int j)
{
   if(i>j)
   {
    return;
   }

   swap(s[i],s[j]);
   i++;
   j--;

   reverse(s,i,j);
}

 int main()
 {
    string name = "navneet";
    reverse(name,0,name.length()-1);
    cout<<name;
 }
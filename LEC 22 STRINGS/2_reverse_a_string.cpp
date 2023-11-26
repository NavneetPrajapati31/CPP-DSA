#include<iostream>
#include<vector>
using namespace std;

void reverse(char name[], int n) 
{
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }

}

int main()
{
    int n;
    cin>>n;
    char name[n];
    cin>>name;

    reverse(name,n);
    cout<<name<<endl;

}
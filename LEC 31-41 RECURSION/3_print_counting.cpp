#include<iostream>
using namespace std;


void printcount(int n)
{
    //base case
    if(n==0)
    {
        return ;
    }

    //recursive relation
    printcount(n-1);
    cout<<n<<endl;
}


int main()
{
    int n;
    cin>>n;

    printcount(n);

    return 0;

}
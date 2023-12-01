#include<iostream>
using namespace std;


void reachhome(int now,int dest)
{
    cout<<"now "<<now<<" "<<"destination "<<dest<<endl;

    //base case
    if(now==dest)
    {
        cout<<"pahuch gya!";
        return ;
   
    }

    //processing
    now++;

    //recursive relation
    reachhome(now,dest);

}


int main()
{
    int n;
    cin>>n;

    reachhome(n,10);

    return 0;

}
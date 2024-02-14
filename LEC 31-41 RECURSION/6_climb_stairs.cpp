#include<iostream>
using namespace std;


int countdistinctways(int nstairs)
{
    //base case
    if(nstairs<0)
    {
        return 0;
    }
    if(nstairs==0)
    {
        return 1;
    }


    //recursive relation
    return countdistinctways(nstairs-1) + countdistinctways(nstairs-2);


}


int main()
{
    int n;
    cin>>n;

    cout<<countdistinctways(n);

    return 0;

}
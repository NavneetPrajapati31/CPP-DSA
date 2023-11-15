//FINDING SQUARE ROOT USING BINARY SEARCH!!
//PRECISION INT AND FLOAT!!


#include<iostream>
using namespace std;


//INT PRECISION

long long int sqrt(int n)
{
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;

    while(s<=e)
    {
        int square = mid*mid;

        if((square)==n)
        {
            return mid;
        }

        else if((square)>n)
        {
            e=mid-1;
        }

        else if((square)<n)
        {
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
return ans;
}

//FLOAT PRECISION

double moreprecision(int n,int precision,int tempsol)
{
    double factor=1;
    double ans=tempsol;

    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j+=factor)
        {
            ans=j;
        }

    }

    return ans;
}


int main()
{
    int n;
    cin>>n;

    cout<<sqrt(n)<<endl;
    int tempsol=sqrt(n);

    cout<<moreprecision(n,3,tempsol);
    return 0;

}
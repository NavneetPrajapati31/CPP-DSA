#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    n = abs(n);

    float ans=0;
    int i=0;

    while(n!=0)
    {
        int bit = n&1;
        ans = bit*pow(10,i) + ans;

        i++;
        n = n>>1;
    }

    cout<<ans<<endl;

    int ans1 = int(ans);
    i=0;
    int val = 0;

    while(ans1!=0)
    {
        int digit = ans1%10;
        digit = !digit;

        val = digit*pow(10,i) + val;

        i++;
        ans1 = ans1/10;
    }

    cout<<val<<endl;

}
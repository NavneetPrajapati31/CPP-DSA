#include<iostream>
using namespace std;


int fastExpo(int a, int b ) {

    int res = 1;

    while(b > 0) {

        if(b&1) {
            //odd
            res = res*a;
        }
        b = b >> 1;
        a = a * a; 
    }
    return res;
}


int modularexpo(int a, int b ,int m) {

    int res = 1;

    while(b > 0)
    {

        if(b&1)
        {
            //odd
            res = (1LL*(res)*(a)%m)%m;
        }
        
        a = (1LL*(a)%m * (a)%m)%m;
        b = b >> 1;
       
    }
    return res;
}


int main() {

    int a,b,m;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b >> m;

    cout << "Answer is: " << fastExpo(a,b) << endl;
    cout << "Answer is: " << modularexpo(a,b,m) << endl;

    return 0;
}
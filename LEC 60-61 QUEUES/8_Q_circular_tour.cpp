//Circular tour : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa1pjTUhZX2lnSFhpU0dvWmVLcldTYmpIVG9jd3xBQ3Jtc0trVG5uZllBOHVYTUUydE42WWFJQlI1LURSOF9MSi03S2l5ZVJsWnNweXhmVC1hTHphbE4zdVFHbHJNYW1PNXdEcmxXZG9vdjlYaFRQa1JxLTE0VUVCbWl1LURxb2RBQ3JLNEdiSHNDYndHb3hLV2wybw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fcircular-tour%2F1&v=_gJ3to4RyeQ


#include<iostream>
#include<queue>
using namespace std;

int tour(petrolPump P[], int n)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for(int i=0;i<n;i++)
    {
        balance = P[i].petrol - P[i].distance;
        if(balance<0)
        {
            deficit+=balance;
            balance =0;
            start = i+1;
        }
    }

    if(deficit+balance >= 0)
    {
        return start;
    }

    else
    return -1;

}
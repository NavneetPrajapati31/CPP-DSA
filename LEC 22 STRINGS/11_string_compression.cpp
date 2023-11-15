#include<iostream>
#include<vector>
using namespace std;


int compress(vector<char> chars)
{
    int i=0;
    int ansindex=0;
    int n=chars.size();

    while(i<n)
    {
        int j=i+1;
        while(j<n && chars[i]==chars[j])
        {
            j++;
        }
        //yaha kab aaoge
        //ya toh vector poora traverse kr diya
        //ya firr new/different char encounter kiya h
 
        //oldchar store karlo
        chars[ansindex++] = chars[i];

        int count = j-i;

        if(count>1)
        {
            //converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for(char ch:cnt)
            {
                chars[ansindex++] = ch;
            }
        }

        i=j;

    }
return ansindex;
}


int main()
{
    vector<char> ch;
   




}
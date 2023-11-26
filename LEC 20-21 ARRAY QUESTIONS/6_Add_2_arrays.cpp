#include<iostream>
#include<vector>

using namespace std;


void printarr(vector<int> arr,int n)
{
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}


vector<int> reverse(vector<int> v) {
    
    int s = 0;
    int e = v.size()-1;
    
    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0 && j>=0) {
        int val1 = a[i];
        int val2 = b[j];
            
        int sum = val1 + val2 + carry;   
        
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    
    // first case
    while(i>=0) {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    
     // second case
    while(j>=0) {
        int sum = b[j] + carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        j--;
    }
    
     // third case
    while(carry != 0) {
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
    //print(ans);
    return reverse(ans);
}


int main()
{
     int n,m,element;
    cin>>n>>m;
    

    vector<int> arr1;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr1.push_back(element);
    }


    vector<int> arr2;
    for(int i=0;i<m;i++)
    {
        cin>>element;
        arr2.push_back(element);
    }

    vector<int> ans;
    for(int i:findArraySum(arr1,n,arr2,m))
    {
        ans.push_back(i);
    }

    printarr(ans,ans.size());


}
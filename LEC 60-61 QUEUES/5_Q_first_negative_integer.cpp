//First negative integer in every window of size K : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbHFOSnFWLXBBbWFUYzBuRVJDUTVsdHpadjRjUXxBQ3Jtc0ttNjRDX2dHQ0VKRzM3dmhsNi1ydW44dEl1NVplMmxsbHdmWXBhdl8wb3BGMkhnVlpveWRIeFdVUFVObnN3OHZibU1VMjBBRXA4TTY2clhXR2tVbkVUMHpPUkQ3RXpUN21NSW43cHN6cTZQSHp4SkhUWQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Ffirst-negative-integer-in-every-window-of-size-k3345%2F1&v=_gJ3to4RyeQ


#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



vector<long long> FirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> dq;
         vector<long long> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<K; i++) {
             if(A[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(A[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=K ) {
                 dq.pop_front();
             }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }
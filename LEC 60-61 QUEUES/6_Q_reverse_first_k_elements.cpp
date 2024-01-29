//Reverse first K element of Queue : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbjNFNThTX0l5SlBQb1MxcFgxeFVjLVdxOHRwZ3xBQ3Jtc0tsTUJTaFJZZ215SW5JZVdBaWdrekktV1JJSVU3YUNqam1kNTF1TVpCazBGZ2pVVDZESWF1cEd2dkdLSU1IdVBuU21meGpqZ1d6a2xTb2w0eVJxazh1Z3plWk9pbVlodzEtaWthSUxuTlpVekZ4bnVSWQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Freverse-first-k-elements-of-queue%2F1%2F&v=_gJ3to4RyeQ

#include<iostream>
#include<stack>
#include<queue>
using namespace std;


class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        stack<int> s;
        
        for(int i=0;i<k;i++)
        {
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        while(!s.empty())
        {
            int val = s.top();
            s.pop();
            q.push(val);
        }
        
        for(int i=0;i<q.size()-k;i++)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
    }
};

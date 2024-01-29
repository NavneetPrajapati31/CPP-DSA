//Queue Reversal : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa0VENjd0Sl9mSEVJUEw5ZnNnVEFzUW5Wb3J4UXxBQ3Jtc0trUVlIclROc1Q4V2Y0Z1FjRVdUS0RJZWx0am54SVl2a1EyT05iRlMxYllONnN1VFE0UENaYnMzaTgxaldrTmhLYjB1SFFha3haVHROcDM0Rkh5VEVhbnFnX3FQNG1rbEJwNUdHSURubkREajRYQ05aaw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fqueue-reversal%2F1&v=_gJ3to4RyeQ


#include<iostream>
#include<stack>
#include<queue>

using namespace std;



class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        
        while(!q.empty())
        {
            int element = q.front();
            s.push(element);
            q.pop();
        }
        
        while(!s.empty())
        {
            int element = s.top();
            s.pop();
            q.push(element);
        }
        
        return q;
    }
};
//First Non-Repeating character in stream : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa1ZDeklQSjFBc3B4aXJfcnlrSWM2TXY3NjM2d3xBQ3Jtc0tuQi1aelhRcHVHQWluSDVOTEdSTktvWG5hZ3k0Y0V0cEhLYlByU19TUENZX0NBYmxoLWgxMk5obEx1Vk92YVZoYzFvMF9VV0RkQmlXZjh3a242QmZHYjhkdzVLMmdLMnRMeXRoalNLYWhTYWt6VHJqRQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Ffirst-non-repeating-character-in-a-stream1216%2F1&v=_gJ3to4RyeQ

#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;


string FirstNonRepeating(string A)
		{
		    unordered_map<char, int> count;
		    queue<int> q;
		    string ans="";
		    
		    for(int i=0;i<A.length();i++)
		    {
		        char ch = A[i];
		        
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty())
		        {
		            if(count[q.front()] >1)
		            {
		                q.pop();
		            }
		            
		            else
		            {
		                ans.push_back(q.front());
		                break;
		                
		            }
		        }
		        
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}
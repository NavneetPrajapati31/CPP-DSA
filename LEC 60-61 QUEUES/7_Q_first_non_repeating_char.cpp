//First Non-Repeating character in stream : https://www.codingninjas.com/studio/problems/first-non-repeating-character_920324

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
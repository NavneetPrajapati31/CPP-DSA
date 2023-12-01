//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbE51TFdmbm5SMGxyb3d3QnRpc0ZiQ3N5blk4Z3xBQ3Jtc0tsWWYtNXlUcEsweFMxMy0tWVlycHFraTNnUGRwMHRsaXRZOGlua2pnelpkWl9kcGRRUkxLbElyQ3Q1R1FuZ2VDMjE1cHh3SzF4SzJRUzMybmJWdnhJWU1iZmpGNU1aZy12WVo2bW9nbV85YU1UUmlTOA&q=https%3A%2F%2Fbit.ly%2F33hi3MB&v=V0IgCltYgg4


#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{
    if(index>=str.length())
    {
        ans.push_back(output);
        return;
    }

    //exclude
    solve(str,output,index+1,ans);

    //include
    char element=str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);

}

vector<string> subsequences(string &str)
    {
         
        vector<string > ans;
        string output;
        int index = 0;
        solve(str, output, index, ans);
        return ans;
        
    }

int main()
{
    string str = "abc";

    cout<<subsequences(str);

}
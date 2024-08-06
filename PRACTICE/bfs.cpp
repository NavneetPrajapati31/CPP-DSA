#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfstraversal(vector<vector<int>> &adjlist, int startingNode, vector<bool> &visited)
{
    queue<int> q;

    visited[startingNode] = true;

    q.push(startingNode);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(auto neighbour:adjlist[node])
        {
            if(!visited[neighbour])
            {
               visited[neighbour] = true;
               q.push(neighbour);
            }
        }
    }
}

void addEdge(vector<vector<int>> &adjlist, int u, int v)
{
    adjlist[u].push_back(v);
}

int main()
{
    int vertices =5;

    vector<vector<int>> adjlist(vertices);
    vector<bool> visited(vertices,false);

    addEdge(adjlist,0,1);
    addEdge(adjlist,0,2);
    addEdge(adjlist,1,3);
    addEdge(adjlist,1,4);
    addEdge(adjlist,2,4);

    bfstraversal(adjlist,0,visited);
}
//https://www.naukri.com/code360/problems/k-sum-path-in-a-binary-tree_893543

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void solve(Node* root,int k, vector<int> path, int &count)
  {
      if(root == NULL)
      {
          return;
      }
      
      path.push_back(root->data);
      
      solve(root->left,k,path,count);
      solve(root->right,k,path,count);
      
      int size = path.size();
      int sum=0;
      
      for(int i=size-1;i>=0;i--)
      {
          sum+=path[i];
          if(sum==k)
          {
              count++;
          }
      }
      
      path.pop_back();
  }
  
    int sumK(Node *root, int k) {
        // code here
        int count=0;
        vector<int> path;
        solve(root,k,path,count);
        return count;
    }
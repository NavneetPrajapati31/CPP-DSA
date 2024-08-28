//https://leetcode.com/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class node
{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a , node* b)
    {
        return a->data > b->data;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        priority_queue<node* , vector<node*> , compare> minHeap;

        for(int i=0;i<lists.size();i++)
        {
            node* temp = new node(lists[i][0].val,i,0);
            minHeap.push(temp);
        }

        while(minHeap.size() > 0)
        {
            ListNode* temp = new ListNode(minHeap.top()->data);
            int i = minHeap.top()->row;
            int j = minHeap.top()->col;

            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }

            else
            {
                tail->next = temp;
            }
            
            minHeap.pop();

            if((j+1) < lists.size())
            {
                ListNode ln = lists[i][j+1];
                node* next = new node(ln.val,i,j+1);
                minHeap.push(next);
            }
        }

        return head;
    }
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* vtoll(vector<int> & ans)
    {
        ListNode *head=nullptr;
        ListNode *tail=nullptr;
        for(int i=0;i<ans.size();i++)
        {
            ListNode* newnode=new ListNode;
            newnode->val=ans[i];
            newnode->next=nullptr;
            if(head==nullptr)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr=head;
        vector<int>v;
        while(ptr!=nullptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        int i=v.size()-n;
        v.erase(v.begin()+i);
        ListNode* start=vtoll(v);
        return start;
    }
};
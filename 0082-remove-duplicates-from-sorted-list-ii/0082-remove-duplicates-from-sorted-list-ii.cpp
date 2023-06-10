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
    ListNode* vtoll(vector<int>& ans)
    {
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        for(int i=0;i<ans.size();i++)
        {
            ListNode* newnode= new ListNode;
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr=head;
        vector<int>v;
        while(ptr!=nullptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        map<int,vector<int>>mp;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]].push_back(i);
        }
        v.clear();
        for(auto i:mp)
        {
            vector<int> sz=mp[i.first];
            if(sz.size()==1)
            {
                v.push_back(i.first);
            }
        }
        ListNode *start=vtoll(v);
        return start;
    }
};
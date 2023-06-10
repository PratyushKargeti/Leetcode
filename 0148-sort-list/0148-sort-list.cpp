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
    ListNode* vtoll(vector<int>& v)
    {
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        for(int i=0;i<v.size();i++)
        {
            ListNode* newnode= new ListNode;
            newnode->val=v[i];
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
    ListNode* sortList(ListNode* head) {
        ListNode* ptr=head;
        vector<int> v;
        while(ptr!=nullptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        sort(v.begin(),v.end());
        ListNode* start=vtoll(v);
        return start;
    }
};
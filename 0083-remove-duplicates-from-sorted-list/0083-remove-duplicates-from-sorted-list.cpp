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
                tail->next =newnode;
                tail=newnode;
            }
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>v;
        ListNode* ptr=head;
        while(ptr!=nullptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        set<int>S;
        S.insert(v.begin(),v.end());
        vector<int>ans;
        for(auto it=S.begin();it!=S.end();it++)
        {
            ans.push_back(*it);
        }
        ListNode *start=vtoll(ans);
        return start;
    }
};
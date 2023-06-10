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
                tail->next=newnode;
                tail=newnode;
            }
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr=head;
        vector<int> v;
        while(ptr!=nullptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }    
        for(int i=0,j=k-1;j<v.size();i=i+k,j=j+k)
        {
            reverse(v.begin()+i,v.begin()+j+1);
        }
        ListNode* start=vtoll(v);
        return start;
    }
};
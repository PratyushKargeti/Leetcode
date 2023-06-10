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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr=head;
        vector<int>ans;
        while(ptr!=nullptr)
        {
            ans.push_back(ptr->val);
            ptr=ptr->next;
        }
        reverse(ans.begin()+(left-1),ans.begin()+right);
        ListNode *start=vtoll(ans);
        return start;       
    }
};
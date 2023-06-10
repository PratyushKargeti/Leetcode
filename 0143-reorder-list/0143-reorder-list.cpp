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
    ListNode* vtoll(vector<int>& res)
    {
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        for(int i=0;i<res.size();i++)
        {
            ListNode* newnode= new ListNode;
            newnode->val=res[i];
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
    void reorderList(ListNode* head) {
        ListNode* ptr=head;
        vector<int> ans;
        while(ptr!=nullptr)
        {
            ans.push_back(ptr->val);
            ptr=ptr->next;
        }
        vector<int>res;
        int i=0;
        int j=ans.size()-1;
        while(i<=j)
        {
            res.push_back(ans[i]);
            if(i==j)
                break;
            res.push_back(ans[j]);
            i++;
            j--;
        }
        ListNode* start=vtoll(res);
        head->next = start->next;
        start->next = nullptr;
    }
};
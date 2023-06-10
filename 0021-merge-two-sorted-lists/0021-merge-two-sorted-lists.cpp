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
        ListNode *head=nullptr;
        ListNode *tail=nullptr;
        for(int i=0;i<res.size();i++)
        {
            ListNode* newnode= new ListNode;
            newnode->val= res[i];
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1=list1;
        ListNode *ptr2=list2;
        vector<int>res;
        while(ptr1!=nullptr)
        {
            res.push_back(ptr1->val);
            ptr1=ptr1->next;
        }
        while(ptr2!=nullptr)
        {
            res.push_back(ptr2->val);
            ptr2=ptr2->next;
        }
        sort(res.begin(),res.end());
        ListNode *head=vtoll(res);
        return head;
    }
};
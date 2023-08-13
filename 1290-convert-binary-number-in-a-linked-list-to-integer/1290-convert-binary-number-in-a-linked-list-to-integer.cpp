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
    int getDecimalValue(ListNode* head) {
        ListNode* ptr=head;
        vector<int>nums;
        while(ptr!=nullptr)
        {
            nums.push_back(ptr->val);
            ptr=ptr->next;
        }
        int sum=0;
        int e=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=nums[i]*pow(2,e);
            e++;
        }
        return sum;
    }
};
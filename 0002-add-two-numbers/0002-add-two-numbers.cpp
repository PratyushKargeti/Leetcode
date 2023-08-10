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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
private:
    ListNode* solve(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2) 
		{
            if (carry == 0)
                return NULL;
            return new ListNode(carry);
        }
        int sum = carry;
        if(l1)
            sum += l1->val;
        if(l2)
            sum += l2->val;

        int new_carry = sum / 10;
        int value = sum % 10;

        ListNode* result = new ListNode(value);

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;

        result->next = solve(l1, l2, new_carry);

        return result;
    }
};

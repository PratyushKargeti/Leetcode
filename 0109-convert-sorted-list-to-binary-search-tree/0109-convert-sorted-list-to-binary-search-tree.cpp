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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&nums,int low,int high)
    {
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        TreeNode* newnode=new TreeNode(nums[mid]);
        newnode->left=solve(nums,low,mid-1);
        newnode->right=solve(nums,mid+1,high);
        return newnode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        ListNode* ptr=head;
        int count=0;
        while(ptr!=NULL)
        {
            count++;
            nums.push_back(ptr->val);
            ptr=ptr->next;
        }
        return solve(nums,0,count-1);
    }
};
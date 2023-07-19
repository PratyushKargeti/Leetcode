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
    void solve(TreeNode*root,vector<int>&path,vector<vector<int>>&v)
    {
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right) v.push_back(path);
        solve(root->left,path,v);
        solve(root->right,path,v);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>v;
        vector<int>path;
        solve(root,path,v);
        vector<vector<int>>ans;
        for(vector<int>&nums:v)
        {
            if(accumulate(nums.begin(),nums.end(),0)==targetSum)
                ans.push_back(nums);
        }
        return ans;
    }
};
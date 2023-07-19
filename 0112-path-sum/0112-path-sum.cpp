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
        if(root==NULL) return;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            v.push_back(path);
        }
        solve(root->left,path,v);
        solve(root->right,path,v);
        path.pop_back();
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>v;
        vector<int>path;
        solve(root,path,v);
        for(vector<int>&nums:v)
        {
            if(accumulate(nums.begin(),nums.end(),0)==targetSum)
                return true;
        }
        return false;
    }
};
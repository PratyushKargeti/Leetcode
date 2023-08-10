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
    vector<int>ans;
    void solve(TreeNode* root, string t) {
        if(!root->left && !root->right) 
        {
            ans.push_back(stoi(t));
            return;
        }
        if(root->left) 
            solve(root->left, t + to_string(root->left->val));
        if(root->right) 
            solve(root->right, t  + to_string(root->right->val));
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        solve(root, to_string(root->val));
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
    }
  
};
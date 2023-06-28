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
    int h;
    int height(TreeNode* root)
    {
        if(root==NULL) 
            return 0;
        else
            return max(1+height(root->left),1+height(root->right));
    }
    int solve(TreeNode*root,int i)
    {
        if(root==NULL)
            return 0;
        if(i==h)
            return root->val;
        return solve(root->left,i+1)+solve(root->right,i+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        h=height(root);
        if(root==NULL) 
            return 0;
        return solve(root,1);
    }
};
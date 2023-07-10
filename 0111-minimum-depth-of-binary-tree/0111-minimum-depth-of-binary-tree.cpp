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
    int ans=INT_MAX;
    void dfs(TreeNode* root,int cnt)
    {
        if(root==NULL)
            return;
        cnt++;
        if(root->left==NULL && root->right==NULL)
        {    
            ans=min(ans,cnt);
            return;
        }
        dfs(root->left,cnt);
        dfs(root->right,cnt);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root,0);
        return ans;
    }
};
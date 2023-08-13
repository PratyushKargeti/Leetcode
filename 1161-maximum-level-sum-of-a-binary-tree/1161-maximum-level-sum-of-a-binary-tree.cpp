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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>row(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                row[i]=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            v.push_back(row);
        }
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            int sum=accumulate(v[i].begin(),v[i].end(),0);
            ans=max(ans,sum);
        }
        for(int i=0;i<v.size();i++)
        {
            if(accumulate(v[i].begin(),v[i].end(),0)==ans)
                return i+1;
        }
        return -1;
    }
};
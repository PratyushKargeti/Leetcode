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
    //int ans=0;
    vector<int>res;
    void dfs(TreeNode* root,int ans)
    {
        if(root==NULL)
            return;
        ans++;
        if(root->left==NULL && root->right==NULL)
        {    
            //ans++;
            res.push_back(ans);
            return;
        }
        dfs(root->left,ans);
        //ans--;
        dfs(root->right,ans);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root,0);
        auto it=min_element(res.begin(),res.end());
        int k=*it;
        return k;
    }
};
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        vector<vector<long long>>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            long long n=q.size();
            vector<long long>row(n);
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
        if(v.size()<k) return -1;
        vector<long long>nums;
        for(int i=0;i<v.size();i++)
        {
            long long sum=accumulate(v[i].begin(),v[i].end(),0LL); //// Use 0LL to ensure long long type sum.
            nums.push_back(sum);
        }
        sort(nums.begin(),nums.end()); 
        return nums[nums.size()-k];
    }
};

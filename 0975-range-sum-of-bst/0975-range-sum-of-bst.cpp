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
    vector<int>v;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=low && v[i]<=high)
                sum+=v[i];    
        }
        return sum;
    }
//     int rangeSumBST(TreeNode* root, int low, int high) {
//     if (root == nullptr) {
//         return 0;
//     }
    
//     if (root->val < low) {
//         return rangeSumBST(root->right, low, high);
//     }
    
//     if (root->val > high) {
//         return rangeSumBST(root->left, low, high);
//     }
    
//     return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
// }

};
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
    TreeNode* invertTree(TreeNode* root) {
        //do postorder traversal(left->right->root),i.e, go left,more left..then right,more right..when come back to root,now swap root->left and root->right
        if(!root) return NULL;
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
};
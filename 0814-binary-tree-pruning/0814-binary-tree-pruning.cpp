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
// class Solution {
// public:
//     TreeNode* postorder(TreeNode* root){
//         if(root==NULL) return NULL;
//         TreeNode* left=postorder(root->left);
//         TreeNode* right=postorder(root->right);
//         if(left==NULL && right==NULL && root->val==0)
//         {
//             delete root;
//             return NULL;
//         }
//         else
//             return root;
//     }
//     TreeNode* pruneTree(TreeNode* root){
//         return postorder(root);
//     }
// };
class Solution {
public:
    TreeNode* postorder(TreeNode* root) {
        if (root == NULL) return NULL;
        
        root->left = postorder(root->left);
        root->right = postorder(root->right);
        // If the current node is a leaf node with value 0, prune it.
        if (root->left == NULL && root->right == NULL && root->val == 0) 
            return NULL;
        else
            return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return postorder(root);
    }
};

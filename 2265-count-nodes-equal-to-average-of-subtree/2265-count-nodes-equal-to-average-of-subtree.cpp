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
int count = 0;

int postorder(TreeNode* root) {
    if (root == NULL) return 0;
    
    int left_sum = postorder(root->left);
    int right_sum = postorder(root->right);
    int sum = left_sum + right_sum + root->val;
    
    int left_c = countNodes(root->left); // Count nodes of the left subtree
    int right_c = countNodes(root->right); // Count nodes of the right subtree
    int c = left_c + right_c + 1; // Calculate the number of nodes in the subtree (including the current node)
    
    int avg = floor(sum / c); // Calculate the average of the subtree
    
    if (avg == root->val) 
        count++;
        
    return sum;
}

int averageOfSubtree(TreeNode* root) {
    postorder(root);
    return count;
}

int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1+countNodes(root->left) + countNodes(root->right);
}

};

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
        v.push_back(root->val);  //jUST USE VECTOR to store them
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);     //The inorder traversal provides a way to retrieve the elements of a BST in a sorted order(ascending). This property is a key characteristic of binary search trees and is useful for various operations and algorithms that rely on sorted data. 
         int ans=INT_MAX;
         for(int i=1;i<v.size();i++)
         {
             ans=min(ans,abs(v[i]-v[i-1]));
         } 
         return ans;
    }
};
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* ptr;
        if(root==NULL) 
            return NULL;
        else if(key<root->val) //search in left subtree
        {
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val) //search in right subtree
        {
            root->right=deleteNode(root->right,key);
        }
        else   //we have found node to delete
        {
            if(root->left==NULL && root->right==NULL) //no child
            {
                delete root;
                return NULL;
            }
            else if(!root->left) // no left child
            {
                ptr=root;
                root=root->right;
                delete ptr;
            }
            else if(!root->right) // no right child
            {
                ptr=root;
                root=root->left;
                delete ptr;
            }
            else  // both child present
            {
                ptr=inordersucc(root->right); //find inorder successor
                root->val=ptr->val;  //swap root's value with it
                root->right=deleteNode(root->right,ptr->val); //delete swapped root value which is present at previous inorder successor's position and return right subtree
            }
        }
        return root;
    }

    TreeNode* inordersucc(TreeNode* root)
    {
        while(root!=NULL && root->left!=NULL) //leftmost node in rightsubtree
            root=root->left;
        return root;
    }
};
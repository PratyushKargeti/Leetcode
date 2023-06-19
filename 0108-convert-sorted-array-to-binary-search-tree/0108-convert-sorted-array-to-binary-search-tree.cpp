class Solution {
public:
//Use Binary search
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if left index becomes greater than right index, return nullptr
        if (left > right) {
            return nullptr;
        }
        
        // Find the middle element of the current range
        int mid = left + (right - left) / 2;
        
        // Create a new TreeNode with the middle element as the value
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};


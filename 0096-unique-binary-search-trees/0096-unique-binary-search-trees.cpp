class Solution {
public:
    int countUniqueBST(int start, int end,vector<vector<int>>&dp) {
        if (start > end)  return 1; // empty subtree is a valid BST (base case)
        if(dp[start][end]!=-1) return dp[start][end];
        
        int totalBSTs = 0;
        for (int i = start; i <= end; i++) 
        {
            int leftCount = countUniqueBST(start, i - 1,dp);
            int rightCount = countUniqueBST(i + 1, end,dp);
            totalBSTs += leftCount * rightCount;
        }
        return dp[start][end]=totalBSTs;
    }   
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return countUniqueBST(1,n,dp);
    }
};
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&mat, vector<vector<int>>&dp,int m,int n)
    {
        if(i == m-1 && j < n && j >= 0) 
            return mat[i][j]; 
        if(j > n-1 || j < 0) 
            return INT_MAX;
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        return dp[i][j]=mat[i][j]+min({solve(i+1,j-1,mat,dp,m,n),solve(i+1,j,mat,dp,m,n),solve(i+1,j+1,mat,dp,m,n)});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        int sum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum=min(sum,solve(0,i,mat,dp,m,n));
        }
        return sum;
    }
};
 //Bottom-up Recursive with memo
// class Solution {
// public:
//     int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
//         if(r == matrix.size()-1 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
//         if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
//         if(dp[r][c] != INT_MAX) return dp[r][c];
//         return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r+1, c-1, dp), minFallingPathSumHelper(matrix, r+1, c, dp)), minFallingPathSumHelper(matrix, r+1, c+1, dp));
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
//         int ans = INT_MAX;
//         for(int c=0; c < cols; c++){
//             ans = min(ans, minFallingPathSumHelper(matrix, 0, c, dp));
//         }
//         return ans;
//     }
// };

class Solution {
public:

    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid,int m,int n)
    {
        if(i==m-1 && j==n-1)
        {
            return grid[i][j]; 
        }
        if(i>m-1 || j>n-1)
            return INT_MAX; //not considered in minimum calculation
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=grid[i][j]+min(solve(i+1,j,dp,grid,m,n),solve(i,j+1,dp,grid,m,n));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int sum=solve(0,0,dp,grid,m,n);
        return sum;
    }
};
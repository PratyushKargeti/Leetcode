class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&ob,int m,int n)
    {
        if(i==m-1 && j==n-1 && ob[i][j]!=1)
            return 1;   // Reached the bottom-right corner without obstacles
        if(i>m-1 || j> n-1 || ob[i][j]==1)
            return 0;  // Out of bounds or obstacle encountered
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]= solve(i+1,j,dp,ob,m,n) + solve(i,j+1,dp,ob,m,n);  // Return precomputed result
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m=ob.size();
        int n=ob[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int x=solve(0,0,dp,ob,m,n);
        return x;
    }
};
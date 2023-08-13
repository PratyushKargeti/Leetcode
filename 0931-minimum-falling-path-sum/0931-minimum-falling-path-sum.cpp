class Solution {
public:
    int solve(int i,int j, vector<vector<int>>&dp,int m,int n,vector<vector<int>>&mat)
    {
        if(i>m-1 || j>n-1 || j<0) return INT_MAX;
        if(i==m-1 && (j>=0 && j<n)) return mat[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int downleft=solve(i+1,j-1,dp,m,n,mat);
        int down=solve(i+1,j,dp,m,n,mat);
        int downright=solve(i+1,j+1,dp,m,n,mat);
        return dp[i][j]=mat[i][j]+min({downleft,down,downright});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX)); //HERE INT_MAX becoz of -ve entries
        int sum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int x=solve(0,i,dp,m,n,mat);
            sum=min(sum,x);
        }
        return sum;
    }
};
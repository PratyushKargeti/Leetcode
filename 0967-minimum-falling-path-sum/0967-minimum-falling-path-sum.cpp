class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&mat, vector<vector<int>>&dp,int m,int n)
    {
        if(i>m-1 || j>n-1 || i<0 || j<0)
        {
            return INT_MAX; //out of bound //INT_MAX values will be ignored for minimum path
        }
        if(i==m-1 || (i==m-1 && j==n-1))
        {
            return mat[i][j]; //base case
        }
        if(dp[i][j]!=INT_MAX) //already-evaluated solution
            return dp[i][j]; 
        return dp[i][j]=mat[i][j]+min({solve(i+1,j-1,mat,dp,m,n),solve(i+1,j,mat,dp,m,n),solve(i+1,j+1,mat,dp,m,n)});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX)); //HERE INT_MAX becoz of -ve entries
        int sum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int x=solve(0,i,mat,dp,m,n);
            sum=min(sum,x);
        }
        return sum;
    }
};
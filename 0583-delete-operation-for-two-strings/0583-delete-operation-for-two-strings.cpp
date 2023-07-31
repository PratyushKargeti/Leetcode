class Solution {
public:
//RECURSION TLE
    // int solve(int m,int n,string s1,string s2)
    // {
    //     if(m<0) return n+1;
    //     if(n<0) return m+1;
        
    //     if(s1[m]==s2[n]) return solve(m-1,n-1,s1,s2);
    //     return 1 + min(solve(m-1,n,s1,s2),solve(m,n-1,s1,s2));
    // }

    // int minDistance(string s1, string s2) {
    //     int m=s1.size();
    //     int n=s2.size();
    //     return solve(m-1,n-1,s1,s2);   
    // }

//memoization(accepted)
    // int solve(int m,int n,vector<vector<int>>&dp,string s1,string s2)
    // {
    //     if(m<0) return n+1;
    //     if(n<0) return m+1;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     if(s1[m]==s2[n]) return dp[m][n]=solve(m-1,n-1,dp,s1,s2);
    //     return dp[m][n]= 1+min(solve(m-1,n,dp,s1,s2),solve(m,n-1,dp,s1,s2));
    // }

    // int minDistance(string s1, string s2) {
    //     int m=s1.size();
    //     int n=s2.size();
    //     vector<vector<int>>dp(501,vector<int>(501,-1));
    //     return solve(m-1,n-1,dp,s1,s2);   
    // }



    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        dp[0][0]=0; //base case
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=j; //base case: when m=0,we need len(s2) deletions
        }
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=i; //base case: when n=0,we need len(s1) deletions
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n]; 
    }
};
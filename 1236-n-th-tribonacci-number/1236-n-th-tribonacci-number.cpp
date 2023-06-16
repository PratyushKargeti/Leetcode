class Solution {
public:
    // int solve(int n,vector<int>&dp)
    // {
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     else
    //     {
    //         if(n<=1)
    //             dp[n]=n;
    //         // if(n==2)
    //         //     dp[n]=dp[1];
    //         else
    //             dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    //     }
    //     return dp[n];
    // }
    // int tribonacci(int n) {
    //     vector<int>dp(n+1,-1);
    //     int ans=solve(n,dp);
    //     return ans;
    // }
    int tribonacci(int n) {
        vector<long long>dp(n+3);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
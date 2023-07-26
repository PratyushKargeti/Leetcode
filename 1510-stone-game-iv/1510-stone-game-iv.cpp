class Solution {
public:
    bool solve(int n,vector<int>&dp)
    {
        if(n<=0) return dp[n]=0; //current player loses game
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            bool opponentmove=solve(n-i*i,dp);
            if(opponentmove==0) return dp[n]=1; //current player wins
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(100001,-1);
        return solve(n,dp);
    }
};
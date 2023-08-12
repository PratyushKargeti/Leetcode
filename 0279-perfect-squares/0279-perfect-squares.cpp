class Solution {
public:
    int solve(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0)
        {
            if(target%coins[0]==0) return target/coins[0];
            return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notpick = 0 + solve(ind-1, target, coins,dp);
        int pick=INT_MAX;
        if(coins[ind]<=target)
        {    
            pick = 1 + solve(ind, target - coins[ind], coins,dp);
        }
        return dp[ind][target]=min(pick,notpick);
    }
    //just put all the perfect squares less than or equal to n in a vector and now its the same problem as the coin change 322.
    int numSquares(int n) {
        vector<int>coins;
        for(int i=1;i*i<=n;i++)
        {
            coins.push_back(i*i);
        }

        vector<vector<int>>dp(coins.size(),vector<int>(n+1,-1));
        return solve(coins.size()-1,n,coins,dp);
    }
};
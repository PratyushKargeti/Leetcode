class Solution {
public:

    int solve(int ind,bool canBuy,vector<vector<int>>&dp,int fee,vector<int>&prices)
    {
        //base case
        if(ind==prices.size()) return 0; //if we bought stock but didnt sell it(mean profit currently -ve) so just return 0 to dont consider -ve profit 
       
        if(dp[ind][canBuy]!=-1) return dp[ind][canBuy];
        int profit=0;
        if(canBuy)
        {
            int buying=-prices[ind]+solve(ind+1,0,dp,fee,prices);
            int notbuying=0+solve(ind+1,1,dp,fee,prices);
            profit=max(buying,notbuying);
        }
        else
        {
            int selling=prices[ind]-fee+solve(ind+1,1,dp,fee,prices);
            int notselling=0+solve(ind+1,0,dp,fee,prices);
            profit=max(selling,notselling);
        }
        return dp[ind][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,dp,fee,prices);
    }
};
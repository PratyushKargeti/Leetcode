class Solution {
public:
//same as Best Time to Buy and Sell Stock II
//just need one more parameter of capacity (2) which will only be reduced
//when one transaction(buy and sell) is done
    int solve(int ind,bool canBuy,int cap,vector<vector<vector<int>>>&dp,vector<int>&prices)
    {
        if(cap==0 || ind==prices.size()) return 0;

        if(dp[ind][canBuy][cap]!=-1) return dp[ind][canBuy][cap];
        
        int profit;
        if(canBuy)
        {
            int buying=-prices[ind]+solve(ind+1,0,cap,dp,prices);
            int notbuying=0+solve(ind+1,1,cap,dp,prices);
            profit=max(buying,notbuying);
        }
        else
        {
            int selling=prices[ind]+solve(ind+1,1,cap-1,dp,prices);
            int notselling=0+solve(ind+1,0,cap,dp,prices);
            profit=max(selling,notselling);
        }
        return dp[ind][canBuy][cap]=profit;
    }
    //since indices can have n different states 0 to n-1
    //since canBuy status can have 2 different states 0/1
    //since capacity(transactions remaining) can have three different states 0/1/2
    //so dp[n][2][3] is required
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1))); //declaring 3d dp
        return solve(0,1,2,dp,prices);
    }
};
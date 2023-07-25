class Solution {
public:
//same as Best Time to Buy and Sell Stock III
//just need one more parameter of capacity (k) which will only be reduced
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
    //since capacity(transactions remaining) can have k+1 different states 
    //0/1/2/.../k
    //so dp[n][2][k+1] is required
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,
                vector<vector<int>>(2,vector<int>(k+1,-1))); 
        return solve(0,1,k,dp,prices);
    }
};


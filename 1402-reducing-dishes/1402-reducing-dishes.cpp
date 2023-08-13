class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&dp,vector<int>&satisfaction)
    {
        //i->current index j->current time
        if(i==n) 
            return 0;
        if(dp[i][j]!=-1) //already computed result, no recursion
            return dp[i][j];
         // Return the maximum of two choices:
        // 1. Cook current index dish with current time taken and move on to the next index dish with time as current time + 1.
        // 2. Skip the current index dish and move on to the next dish at the same time.
        return dp[i][j]=max(satisfaction[i]*j +solve(i+1,j+1,n,dp,satisfaction) , solve(i+1,j,n,dp,satisfaction));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        //to maximize the sum, we need to ensure that the dishes with high satisfaction value get cooked later as they will be multiplied by a larger time coefficient hence sort
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)); //dp table 
        int ans=solve(0,1,n,dp,satisfaction);
        return ans;
    }
};
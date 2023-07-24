class Solution {
public:
    //recursion (TLE)
    // int solve(int ind,vector<int>&nums)
    // {
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     int pick=nums[ind]+solve(ind-2,nums);
    //     int notpick=0+solve(ind-1,nums);
    //     return max(pick,notpick);        
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     return solve(n-1,nums);
    // }

    //there are overlapping subproblems
    //using memoization
    int solve(int ind,vector<int>&dp,vector<int>&nums)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(ind-2,dp,nums);
        int notpick=0+solve(ind-1,dp,nums);
        return dp[ind]=max(pick,notpick);        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);
    }
};
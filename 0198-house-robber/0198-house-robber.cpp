class Solution {
public:
    //recursion (TLE)  O(2^n)
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
    //using memoization   O(n),O(n)+O(n)
    // int solve(int ind,vector<int>&dp,vector<int>&nums)
    // {
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int pick=nums[ind]+solve(ind-2,dp,nums);
    //     int notpick=0+solve(ind-1,dp,nums);
    //     return dp[ind]=max(pick,notpick);        
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,-1);
    //     return solve(n-1,dp,nums);
    // }

    //tabulation (bottom up) O(n),O(n)
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,-1);
    //     dp[0]=nums[0]; //base case
    //     int neg=0; //base case (for out of bounds)
    //     for(int i=1;i<n;i++)
    //     {
    //         int pick,notpick;
    //         if(i-2<0) pick=nums[i]+neg;
    //         else pick=nums[i]+dp[i-2];  
    //         notpick=0+dp[i-1];
    //         dp[i]=max(pick,notpick);
    //     }
    //     return dp[n-1];
    // }

    //space optimization (we dont need entire dp array, instead only two variables denoting two previous values from current position)
    //O(n),O(1)
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0]; //base case
        int prev2=0; //base case (for out of bounds)
        for(int i=1;i<n;i++)
        {
            int pick=nums[i]+prev2;  
            int notpick=0+prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
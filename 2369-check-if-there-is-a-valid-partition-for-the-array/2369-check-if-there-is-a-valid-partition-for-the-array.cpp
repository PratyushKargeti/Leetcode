class Solution {
public:
    bool solve(int i,vector<int>& dp,vector<int>& nums) {
        if(i<0) return true; //successfully traversed entire array valid partition
        if (dp[i]!=-1) return dp[i];

        bool res = false;
        // Check two equal elements
        if (i-1 >= 0 && nums[i]==nums[i - 1])
            res = res||solve(i-2,dp,nums);
        // Check three equal elements
        if (i-2>=0 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2])
            res = res || solve(i-3,dp,nums);
        // Check three consecutive elements
        if (i-2>=0 && nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1)
            res = res || solve(i-3,dp,nums);
        return dp[i] = res;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(n - 1, dp, nums);
    }
};

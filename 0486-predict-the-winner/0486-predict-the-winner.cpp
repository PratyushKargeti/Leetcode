class Solution {
public:
    int solve(int s,int e,vector<vector<int>>&dp,vector<int>&nums)
    {       
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        return dp[s][e]=max(nums[s]-solve(s+1,e,dp,nums),nums[e]-solve(s,e-1,dp,nums));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(21,vector<int>(21,-1));
        int x=solve(0,n-1,dp,nums);
        if(x>=0) return true;
        else return false;
    }
};
class Solution {
public:
    int solve(int ind,vector<int>&nums,int target,int n,int sum)
    {
        if(ind==n)
        {
            if(sum==target)
                return 1;
            return 0;
        }
        return solve(ind+1,nums,target,n,sum-nums[ind]) + solve(ind+1,nums,target,n,sum+nums[ind]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,nums,target,nums.size(),0);
    }
};
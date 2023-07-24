class Solution {
public:
    int solve(vector<int>&nums)
    {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
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
    //simliar as houserobber 1 but here first and last element both cannot be in answer
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr1,arr2;
        if(n==1) return nums[0]; //edge case: when there is only one element
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        return max(solve(arr1),solve(arr2));
    }
};
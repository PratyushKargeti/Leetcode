class Solution 
{
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        //int n=nums.size();
        vector<int> ans(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            ans[i]=sum;
        }
        return ans;

    }
};
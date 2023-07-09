class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=nums[0];
        int max_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr_sum=max(nums[i],curr_sum+nums[i]); //update current sum
            if(curr_sum > max_sum) 
                max_sum=curr_sum; //update maxsum
        }
        return max_sum;
    }
};
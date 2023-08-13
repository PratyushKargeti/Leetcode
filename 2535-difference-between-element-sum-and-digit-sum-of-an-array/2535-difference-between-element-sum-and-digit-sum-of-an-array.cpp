class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elesum=0;
        int digsum=0;
        for(int i=0;i<nums.size();i++)
        {
            elesum+=nums[i];
            while(nums[i]>0)
            {
                int dig=nums[i]%10;
                digsum+=dig;
                nums[i]/=10;
            }
        }
        return (elesum-digsum);
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<even.size();i++)
        {
            nums.push_back(even[i]);
            nums.push_back(odd[i]);
        }
        return nums;
    }
};
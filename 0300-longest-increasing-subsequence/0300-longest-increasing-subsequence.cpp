class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        v.push_back(nums[0]);
        int l=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>v.back())
            {
                v.push_back(nums[i]);
                l++;
            }
            else
            {
                //find first index  in range which is > nums[i]
                int ind=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[ind]=nums[i]; //simple overwrite that index
            }
        }
        return l;
    }
};
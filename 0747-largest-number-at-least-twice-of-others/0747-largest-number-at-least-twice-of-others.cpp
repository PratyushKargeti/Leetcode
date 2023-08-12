class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it=max_element(nums.begin(),nums.end());
        int maxi=*it;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=maxi && maxi>=2*nums[i])
            {
                count++;
            }
        }
        if(count==nums.size()-1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==maxi)
                    return i;
            }
        }
        return -1;
    }
};
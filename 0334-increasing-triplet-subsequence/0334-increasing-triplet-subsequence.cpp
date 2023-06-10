class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if(nums.size()<3) 
            return false;
        int l1=INT_MAX,l2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=l1) 
                l1=nums[i];
            else if(nums[i]<=l2) 
                l2=nums[i];
            else 
                return true;
        }
        return false;
    }
};
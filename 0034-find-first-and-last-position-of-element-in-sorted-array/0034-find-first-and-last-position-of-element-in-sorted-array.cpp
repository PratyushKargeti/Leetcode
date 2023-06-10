class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int founds=-1;
        int founde=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                founds=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==target)
            {
                founde=i;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(founds);
        ans.push_back(founde);
        return ans;
    }
};
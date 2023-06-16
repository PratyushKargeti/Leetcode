class Solution {
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        int n=nums.size();
        int j=0;
        int count=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};
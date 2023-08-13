class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n);
        for(int i=0;i<n;i++)
        {
            count[i]=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]< nums[i])
                {
                    count[i]++;
                }
            }
        }
        return count;
    }
};
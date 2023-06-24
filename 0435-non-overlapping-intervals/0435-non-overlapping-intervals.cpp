class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        //simple activity selection
        sort(nums.begin(),nums.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int count=0;
        int cmp=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i][0]>=cmp)
            {
                count++;
                cmp=nums[i][1];
            }
        }
        return nums.size()-count;
    }
};
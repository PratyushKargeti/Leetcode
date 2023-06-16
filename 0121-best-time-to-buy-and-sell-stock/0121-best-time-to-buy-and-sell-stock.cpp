class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int minsofar=nums[0];
        int maxprof=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            minsofar=min(minsofar,nums[i]);
            int currentprofit=nums[i+1]-minsofar;
            maxprof=max(maxprof,currentprofit);   
        }
        return maxprof;
    }
};
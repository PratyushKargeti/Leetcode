class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        vector<int> leftSum;
        vector<int> rightSum;
        int lsum=0,rsum=0;
        for(int i=0;i<nums.size();i++)
        {
            lsum=0;
            for(int j=i-1;j>=0;j--)
            {
                lsum+=nums[j];
            }
            leftSum.push_back(lsum);
            rsum=0;
            for(int k=i+1;k<nums.size();k++)
            {
                rsum+=nums[k];
            }
            rightSum.push_back(rsum);
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
    }
};
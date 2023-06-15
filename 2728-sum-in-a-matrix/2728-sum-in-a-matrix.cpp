class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            sort(nums[i].begin(),nums[i].end(),greater<int>());
        }
        int sum=0;
        for(int j=0;j<nums[0].size();j++)
        {   
            int maxx=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                maxx=max(maxx,nums[i][j]);
            }
            sum+=maxx;
        }   
        return sum;
    }
};
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> v;
        int flag=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==0)
                {
                    flag=1;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                }
            }
        }
        if(flag==0)
        {
            return -1;
        }
        sort(v.begin(),v.end());
        return v[v.size()-1];
    }
};
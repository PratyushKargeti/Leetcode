class Solution {
public:
    int func(int num)
    {
        int sod=0;
        while(num>0)
        {
            sod+=num%10;
            num/=10;
        }
        return sod;
    }
    int maximumSum(vector<int>& nums) {
        map<int,int>m;
        int maxi=-1;
        for(int i=0;i<nums.size();i++)
        {
            int sod= func(nums[i]);
            if(m.count(sod)>0)
            {
                maxi=max(maxi,nums[i]+m[sod]);
                if(nums[i]>m[sod])
                    m[sod]=nums[i];
            }
            else
            {
                m[sod]+=nums[i];
            }
        }
        return maxi;
    }
};
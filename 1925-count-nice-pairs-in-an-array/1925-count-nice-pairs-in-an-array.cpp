class Solution {
public:
    int mod=1e9+7;
    int rev(int num)
    {
        int rev=0;
        while(num>0)
        {
            rev=rev*10+(num%10);
            num/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        long long ans=0;
        map<long long,long long>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]-rev(nums[i])]++;
        }
        for(auto i:m)
        {
            ans+=i.second*(i.second-1)/2;
        }
        return ans%mod;
    }
};
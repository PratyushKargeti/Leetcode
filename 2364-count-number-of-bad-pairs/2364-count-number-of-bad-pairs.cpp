class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        map<long long,long long>m;
        long long ans=n*(n-1)/2; //total pairs
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]-i]++; //stores count of good pairs formed by ith element
        }
        for(auto i:m)
        {
            long long goodpairs= i.second*(i.second-1)/2;
            ans-=goodpairs;
        }
        return ans;        
    }
};
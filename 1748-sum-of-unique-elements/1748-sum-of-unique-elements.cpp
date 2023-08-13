class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        // int sum=0,x;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int x=count(nums.begin(),nums.end(),nums[i]);
        //     if(x==1)
        //     {
        //         sum+=nums[i];
        //     }
        // }
        // return sum;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int sum=0;
        for(auto i:mp)
        {
            if(i.second==1)
                sum+=i.first;
        }
        return sum;
    }

};
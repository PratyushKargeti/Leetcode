class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int i;
        // for(i=0;i<nums.size();i++)
        // {
        //     if(count(nums.begin(),nums.end(),nums[i])==1)
        //         break;
        // }
        // return nums[i];
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(auto i:mp)
        {
            if(i.second.size()==1)
            {
                return i.first;
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        nums.clear();
        for(auto i:mp)
        {
            if(i.second.size()==1)
            {
                nums.push_back(i.first);
            }
        }
        return nums;
    }
};
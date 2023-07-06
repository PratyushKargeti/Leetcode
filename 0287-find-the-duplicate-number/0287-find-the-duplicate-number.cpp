class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // map<int,vector<int>>mp;
        // for(int i=0;i<nums.size();i++)
        //     mp[nums[i]].push_back(i);
        // for(auto i:mp)
        // {
        //     if(i.second.size()>=2)
        //          return i.first;
        // }
        // return -1;    
         
        while(nums[0]!=nums[nums[0]])
        {
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};
class Solution {
public:
    void solve(int ind,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int>S;
        for(int i=ind;i<nums.size();i++)
        {
           if(S.find(nums[i])!=S.end()) continue;
            S.insert(nums[i]);
            swap(nums[ind],nums[i]);
            solve(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,ans,nums);
        return ans;
    }
};
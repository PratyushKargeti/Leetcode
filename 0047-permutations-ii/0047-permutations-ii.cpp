class Solution {
public:
    void solve(vector<int>&ds,vector<bool>&visited,vector<vector<int>>&ans,vector<int>&nums)
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i=0;i<nums.size();i++)
        {
            if (visited[i]==false)
            {
                if(i>0 && nums[i]==nums[i - 1] && !visited[i-1]) continue;
                ds.push_back(nums[i]);
                visited[i] = true;
                solve(ds,visited,ans,nums);
                ds.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>>ans;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);
        solve(ds,visited,ans,nums);
        return ans;
    }
};
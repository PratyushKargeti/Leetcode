class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,vector<int>&ds,vector<int>&nums)
    {
        if(ind==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        solve(ind+1,ds,nums);
        ds.pop_back();
        solve(ind+1,ds,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        solve(0,ds,nums);
        return ans;
    }
};
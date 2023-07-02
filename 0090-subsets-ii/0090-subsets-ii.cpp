class Solution {
public:
    void solve(int ind,vector<int>&ds,vector<int>&nums,set<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[ind]);
        solve(ind+1,ds,nums,ans);
        ds.pop_back();
        solve(ind+1,ds,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        set<vector<int>>ans;
        solve(0,ds,nums,ans);
        vector<vector<int>>res;
        for(auto i:ans)
        {
            res.push_back(i);
        }
        return res;
    }
};
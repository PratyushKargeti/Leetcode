class Solution {
public:
    void solve(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums)
    {
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {   
            if(i>ind && nums[i]==nums[i-1]) continue;

            ds.push_back(nums[i]);
            solve(i+1,ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        solve(0,ds,ans,nums);
        return ans;
    }
    // void solve(int ind,vector<int>&ds,vector<int>&nums,set<vector<int>>&ans)
    // {
    //     if(ind==nums.size())
    //     {
    //         ans.insert(ds);
    //         return;
    //     }
    //     ds.push_back(nums[ind]);
    //     solve(ind+1,ds,nums,ans);
    //     ds.pop_back();
    //     solve(ind+1,ds,nums,ans);
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     vector<int>ds;
    //     set<vector<int>>ans;
    //     solve(0,ds,nums,ans);
    //     vector<vector<int>>res;
    //     for(auto i:ans)
    //     {
    //         res.push_back(i);
    //     }
    //     return res;
    // }
};
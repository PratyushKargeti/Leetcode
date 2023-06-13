class Solution {
public:
    void solve(int ind,vector<int>&v,vector<vector<int>>&vec,vector<int>&nums)
    {
        if(ind==nums.size())
        {
            vec.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,v,vec,nums);
        v.pop_back();
        solve(ind+1,v,vec,nums);     
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int>v;
        solve(0,v,vec,nums);
        return vec;
    }
};

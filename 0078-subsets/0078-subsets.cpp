class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int n,int ind,vector<int>& v)
    {
        if(ind==n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(nums,n,ind+1,v);
        v.pop_back();
        solve(nums,n,ind+1,v);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(nums,nums.size(),0,v);
        return ans;
    }
};
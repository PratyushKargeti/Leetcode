class Solution {
public:
    void solve(int ind,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(ds);
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
        vector<vector<int>>ans;
        solve(0,ds,nums,ans);
        set<vector<int>>S;
        S.insert(ans.begin(),ans.end());
        ans.clear();
        ans.assign(S.begin(),S.end());
        return ans;
    }
};
class Solution {
public:
    void solve(int ind,vector<int>&ds,vector<int>&nums,set<vector<int>>&ans,int k)
    {
        if(ind==nums.size())
        {
            if(ds.size()==k)
            {
                ans.insert(ds);
            }     
            return;
        }
        ds.push_back(nums[ind]);
        solve(ind+1,ds,nums,ans,k);
        ds.pop_back();
        solve(ind+1,ds,nums,ans,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<int>ds;
        solve(0,ds,nums,ans,k);
        vector<vector<int>>res;
        for(auto i:ans)
        {
            res.push_back(i);
        }
        return res;
    }
};
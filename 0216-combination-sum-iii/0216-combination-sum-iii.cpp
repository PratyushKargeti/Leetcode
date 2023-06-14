class Solution {
public:
    void solve(int ind,int n,int k,vector<vector<int>>&ans,vector<int>&v)
    {
        if(v.size()==k)
        {
            if(n==0)
                ans.push_back(v);
            return;
        }
        for(int i=ind;i<10;i++)
        {
            if(i>n) 
                return;
            v.push_back(i);
            solve(i+1,n-i,k,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(1,n,k,ans,v);
        return ans;
    }
};
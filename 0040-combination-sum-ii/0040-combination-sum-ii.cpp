class Solution {
public:

    void solve(int index,vector<vector<int>>&ans,vector<int>&v,int target,vector<int>&arr)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=index;i<arr.size();i++)
        {
            if(arr[i]>target)
                return;
            if(i>index && arr[i]==arr[i-1])
                continue;
            v.push_back(arr[i]);
            solve(i+1,ans,v,target-arr[i],arr);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,v,target,candidates);
        return ans;
    }  
};
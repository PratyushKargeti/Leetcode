class Solution {
public:
    void solve(int ind,vector<int>& v,vector<vector<int>>& ans,int target,vector<int>&arr){
        if(ind==arr.size())
        {
            if(target==0)
                ans.push_back(v);
            return;
        }
        if(arr[ind]<=target)
        {
            v.push_back(arr[ind]);
            solve(ind,v,ans,target-arr[ind],arr);
            v.pop_back();
        }
        solve(ind+1,v,ans,target,arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,v,ans,target,candidates);   
        return ans;
    }
};
class Solution {
public:
    void solve(int ind,int target,vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            if(target==0) //we simple push and return
            {
                ans.push_back(ds);
            }
            return; //if target is not zero - invalid combination so return to
            //return to previous call
        }
        //pick case condition
        if(nums[ind]<=target)
        {
            ds.push_back(nums[ind]);
            solve(ind,target-nums[ind],ds,nums,ans);
            ds.pop_back();
        }            
        //not pick
        solve(ind+1,target,ds,nums,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,ds,nums,ans);
        return ans;
    }
};
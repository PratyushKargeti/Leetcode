class Solution {
public:
    void solve(int ind,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums); 
            return;   
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            solve(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,ans,nums);
        return ans;              
    }
    // void solve(vector<int>&ds,vector<vector<int>>&ans,vector<bool>&visited,vector<int>&nums)
    // {
    //     if(ds.size()==nums.size())
    //     {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(visited[i]==false)
    //         {
    //             ds.push_back(nums[i]);
    //             visited[i]=true;
    //             solve(ds,ans,visited,nums);
    //             ds.pop_back();
    //             visited[i]=false;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>>ans;
    //     vector<int>ds;
    //     vector<bool>visited(nums.size(),false);
    //     solve(ds,ans,visited,nums);
    //     return ans;              
    // }
};
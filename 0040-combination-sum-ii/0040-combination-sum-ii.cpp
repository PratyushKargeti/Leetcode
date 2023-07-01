class Solution {
public:
    void solve(int ind,int target,vector<int>&ds,vector<int>&cand,vector<vector<int>>&ans)
    {
        if(target==0)
        {        
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<cand.size() && cand[i]<=target ;i++)
        { 
            if(i>ind && cand[i]==cand[i-1]) continue; 
            //i>ind condition is added for a condition where i==ind in      beginnning of rec call and cand[i]==cand[i-1] in that case cand[i] should be added if cand[i]<=target

            ds.push_back(cand[i]);
            //we will reduce target
            solve(i+1,target-cand[i],ds,cand,ans);
            ds.pop_back(); //to go back to previous state
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
      sort(cand.begin(),cand.end()); //compulsory step
      vector<vector<int>>ans;
      vector<int>ds;
      solve(0,target,ds,cand,ans);
      return ans;
  }
    //TLE BRUTE FORCE BEST TRY
    // void solve(int ind,int target,vector<int>&ds,vector<int>&cand,set<vector<int>>&ans)
    // {
    //     if(ind==cand.size())
    //     {
    //         if(target==0)
    //         {
    //             ans.insert(ds);
    //         }
    //         return;
    //     }
    //     if(cand[ind]<=target)
    //     {
    //         ds.push_back(cand[ind]);
    //         solve(ind+1,target-cand[ind],ds,cand,ans);
    //         ds.pop_back();
    //     }
    //     solve(ind+1,target,ds,cand,ans);
    // }
    // vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
    //     sort(cand.begin(),cand.end());
    //     set<vector<int>>ans;
    //     vector<int>ds;
    //     solve(0,target,ds,cand,ans);
    //     vector<vector<int>>res;
    //     for(auto i:ans)
    //     {
    //         res.push_back(i);
    //     }
    //     return res;
    // }
};
class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&dp,vector<int>&satisfaction)
    {
        //i->index j->time
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(satisfaction[i]*j +solve(i+1,j+1,n,dp,satisfaction) , solve(i+1,j,n,dp,satisfaction));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(0,1,n,dp,satisfaction);
        return ans;
    }
};
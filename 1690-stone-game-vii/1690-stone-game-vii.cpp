class Solution {
public:
    //Example
    // [3,2,5,7,6,1] , i=0, j=5
    // P=[0,3,5,10,17,23,24]
    // rightsum=P[6]-P[1] (from i+1 to j)
    // leftsum=P[5]-P[0] (from i to j-1)

    int solve(int i,int j,vector<int>&P,vector<vector<int>>&dp,vector<int>&stones)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int rightsum=P[j+1]-P[i+1]; 
        int leftsum=P[j]-P[i];
        //we cannot go greedy here because it doesn't take into account the future moves of the opponent, which is crucial for maximizing the final difference in the total stone values between the players...we need to consider both options
        //if both play optimally,difference btw current move and opponent's
        //next move has to be maximised
        return dp[i][j]=max(rightsum-solve(i+1,j,P,dp,stones),leftsum-solve(i,j-1,P,dp,stones));
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int>P(n+1,0); //using prefix array
        for(int i=0;i<n;i++)
        {
            P[i+1]=P[i]+stones[i];
        }
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return solve(0,n-1,P,dp,stones);
    }
};
class Solution {
public:
    int solve(int s, int e, vector<vector<int>>& dp, vector<int>& stones) {
        if(s>=e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int rs=accumulate(stones.begin()+s,stones.begin()+e+1,0);
        int ans=0;
        int ls=0;
        //there can be maximum n-1 elements in left part
        //right part must have atleast one element(last element)
        for(int i=s;i<e;i++)
        {
            ls+=stones[i]; 
            rs-=stones[i];
            if(ls<rs) //take current leftsum and choose left part
                ans=max(ans,ls+solve(s,i,dp,stones));
            else if(rs<ls)//take current rightsum and choose right part
                ans=max(ans,rs+solve(i+1,e,dp,stones));
            else //choose max of two options               
                ans=max(ans,max(ls+solve(s,i,dp,stones),rs+solve(i+1,e,dp,stones)));
        }
        return dp[s][e]=ans;
    }

    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,dp,stones);
    }
};
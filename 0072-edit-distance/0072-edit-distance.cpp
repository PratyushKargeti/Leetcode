class Solution {
public:
    //memoization
    // int solve(int i,int j,vector<vector<int>>&dp,string& word1,string& word2) {
    //     if(i==0) return j;
    //     if(j==0) return i;
    //     if (dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i-1]==word2[j-1])
    //         return dp[i][j]=solve(i-1,j-1,dp,word1,word2);
    //     int insertOp=solve(i,j-1,dp,word1,word2);
    //     int deleteOp=solve(i-1,j,dp,word1,word2);
    //     int replaceOp=solve(i-1,j-1,dp,word1,word2);
    //     return dp[i][j]=1+min({insertOp, deleteOp, replaceOp});
    // }
    // int minDistance(string word1, string word2) {
    //     int m=word1.size();
    //     int n=word2.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     return solve(m,n,dp,word1,word2);
    // }

    //tabulation
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        //dp table will store min no.of operations
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        //base case1: if second string is null 
        for(int i=0;i<=m;i++) dp[i][0]=i;
        //base case2: if first string is null 
        for(int i=0;i<=n;i++) dp[0][i]=i;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1]) //if same current char
                {
                    //check in remaining part of both strings
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    int ins=dp[i][j-1]; //insert
                    int del=dp[i-1][j]; //delete
                    int rep=dp[i-1][j-1];//replace
                    dp[i][j]=1+min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
    }

};
class Solution {
public:
    int lcs(string s,string t)
    {
        int m=s.size(); 
        int n=t.size(); //note here m=n
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        //if any of string is null,lcs is 0 
        for(int i=0;i<=m;i++) dp[i][0]=0;  
        for(int i=0;i<=n;i++) dp[0][i]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    //lcs of string and reverse of string is answer
    int longestPalindromeSubseq(string s) {
        string t(s);
        reverse(t.begin(),t.end());
        return lcs(s,t); //simple lcs code
    }
};
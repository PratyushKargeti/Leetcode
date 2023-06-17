class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>c(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                    c[i][j]=1+c[i-1][j-1];
                else
                    c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
        return c[m][n];
    }
};
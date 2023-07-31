class Solution {
public:
    //recursion- TLE
//     int solve(int m,int n,string s1,string s2)
//     {
        
//         if(m<0)
//         {
//             int sum=0;
//             for(int i=0;i<=n;i++)
//             {
//                 sum+=s2[i];
//             }
//             return sum;
//         }
//         if(n<0)
//         {
//             int sum2=0;
//             for(int i=0;i<=m;i++)
//             {
//                 sum2+=s1[i];
//             }
//             return sum2;
//         }
//         if(s1[m]==s2[n]) return solve(m-1,n-1,s1,s2);
//         else
//         {
//             return min({s1[m]+solve(m-1,n,s1,s2),s2[n]+solve(m,n-1,s1,s2),s1[m]+s2[n]+solve(m-1,n-1,s1,s2)});
//         }
//     }
//     int minimumDeleteSum(string s1, string s2) {
//         int m=s1.size();
//         int n=s2.size();
        
//         return solve(m-1,n-1,s1,s2);
//     }

    //MEMOIZATION - MEMORY EXCEEDED
//     int solve(int m,int n,vector<vector<int>>&dp,string s1,string s2)
//     {
        
//         if(m<0)
//         {
//             int sum=0;
//             for(int i=0;i<=n;i++)
//             {
//                 sum+=s2[i];
//             }
//             return sum;
//         }
//         if(n<0)
//         {
//             int sum2=0;
//             for(int i=0;i<=m;i++)
//             {
//                 sum2+=s1[i];
//             }
//             return sum2;
//         }
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(s1[m]==s2[n]) return dp[m][n]=solve(m-1,n-1,dp,s1,s2);

//         return dp[m][n]=min({s1[m]+solve(m-1,n,dp,s1,s2),s2[n]+solve(m,n-1,dp,s1,s2),s1[m]+s2[n]+solve(m-1,n-1,dp,s1,s2)});
        
//     }
//     int minimumDeleteSum(string s1, string s2) {
//         int m=s1.size();
//         int n=s2.size();
//         vector<vector<int>>dp(1001,vector<int>(1001,-1));
//         return solve(m-1,n-1,dp,s1,s2);
//     }

    
    //TABULATION (ACCEPTED)
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=0; //base case
        int sum=0;
        for(int j=1;j<=n;j++) 
        {
            sum+=s2[j-1];
            dp[0][j]=sum; //base case:filling table for case when m=0
        }
        int sum2=0;
        for(int i=1;i<=m;i++)
        {
            sum2+=s1[i-1];
            dp[i][0]=sum2; //base case:filling table for case when n=0
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1],s1[i-1]+s2[j-1]+dp[i-1][j-1]});    
            }
        }
       return dp[m][n];
    }
};
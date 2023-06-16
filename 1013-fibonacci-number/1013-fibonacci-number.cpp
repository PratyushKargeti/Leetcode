class Solution {
public:
//     int lookupfn(int n,vector<int>&lookup)
//     {
//         if(lookup[n]<INT_MAX)
//             return lookup[n];
//         else
//         {
//             if(n<=1)
//                 lookup[n]=n;
//             else
//                 lookup[n]=lookupfn(n-1,lookup)+lookupfn(n-2,lookup);
//         }
//         return lookup[n];
//     }

//     int fib(int n) {
// //Using memoization
//         vector<int> lookup(n+1,INT_MAX);
//         return lookupfn(n,lookup);
//     }
    int fib(int n) {
        vector<int>dp(n+2);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
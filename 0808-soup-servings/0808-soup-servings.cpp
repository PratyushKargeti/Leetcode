class Solution {
public:
    double soupServings(int n) {
        if(n == 0)
            return 0.5;
        //A is easier to be empty than B. And when N gets bigger, we have less chance to run out of B first. So as N increases, our result increases and it gets closer to 100 percent = 1.Answers within 10^-5 of the true value will be accepted as correct. Now it's obvious that when N is big enough, result is close enough to 1 and we just need to return 1.When N = 4800, the result = 0.999994994426 , When N = 4801, the result = 0.999995382315. So if N>= 4800, just return 1 and it will be enough.
        if(n > 4800) 
            return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        solve(n,n,dp);
        return dp[n][n];
    }
    double solve(int A,int B,vector<vector<double>>&dp) {
        if(A==0 && B==0) return 0.5; // both have been fully served,50% chance of this happening.
        if(A==0 || B==0) return A==0 ? 1.0 : 0; //means one type of soup has been fully served. If A is empty, it returns 1.0 (100% chance) since the problem statement asks for A to be empty first. Otherwise, if B is empty, it returns 0 (0% chance) since it's not possible to empty Soup B first as per the operations.
        if(dp[A][B] != -1) return dp[A][B];
        double ans = 0;
        for(int i=25;i<=100;i+=25)
        {
            //max(0, A - i) ensures that the number of servings cannot be negative, so it is capped at 0.
            ans+=0.25*solve(max(0,A-i),max(0,B-(100-i)),dp);//calculating probability of serving Soup A with i servings (where i can be 25, 50, 75, or 100) and Soup B with (100 - i) servings. For total probability x0.25 (25%) as there are four steps, each with an equal chance of occurrence.
        }
        return dp[A][B]=ans;
    }
};
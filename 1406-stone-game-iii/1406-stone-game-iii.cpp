class Solution {
public:
    // //ind: The current index in the stones vector.
    // //m: The maximum number of stones a player can pick in one turn.
    // //player: The current player (0 for Alice, 1 for Bob).
    // //dp: memoization table to store the computed results for subproblems.
    // //stones: The input vector of stones.
    // //n: The total number of stones.

    // //note dimensions are dp[n+1][4][2] since ind can go from 0 to n(n because that is base case,so n+1 states) , m goes from 1 to 3 (but for base case no stone to pick so overall we can take max(m)+1 states) , player are 2(alice and bob)
    
    // int solve(int ind, int m, int player, vector<vector<vector<int>>>& dp, vector<int>& stones,int n) {
    //     if (ind >= n) return 0;
    //     if (dp[ind][m][player] != INT_MIN) return dp[ind][m][player];
        
    //     int scorediff = INT_MIN; 
    //     int currSum = 0;
        
    //     for (int x=1;x<=3 && ind+x<=n;x++) 
    //     {
    //         currSum += stones[ind+x-1];
    //         //Update scorediff to be the maximum  difference between currSum and the score obtained by the other player in the next state.  
    //         scorediff = max(scorediff,currSum-solve(ind+x,max(m,x),1-player, dp,stones,n));//represents the maximum score difference the current player can achieve by making the move x.
    //     }
    //     return dp[ind][m][player] = scorediff;
    // }
    
    // string stoneGameIII(vector<int>& stones) {
    //     int n = stones.size();
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(4, vector<int>(2, INT_MIN)));

    //     //we will find score difference for Alice
    //     int aliceScorediff=solve(0,1,0,dp,stones,n);
        
    //     if (aliceScorediff > 0) return "Alice";
    //     else if (aliceScorediff < 0) return "Bob";
    //     else return "Tie";
    // }


    int solve(int ind, vector<int>& dp, vector<int>& stones,int n){
        if(ind >= n) return 0;
        if(dp[ind] != INT_MIN) return dp[ind];
    
        int scorediff = INT_MIN; 
        int currSum = 0;
        
        for(int x = 1; x <= 3 && ind+x<=n; x++) 
        {
            currSum += stones[ind+x-1];
            scorediff=max(scorediff,currSum-solve(ind+x,dp,stones,n));
        }
        return dp[ind] = scorediff;
    }

    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>dp(n+1,INT_MIN);
        int aliceScorediff = solve(0,dp,stones,n);
        if(aliceScorediff > 0) return "Alice";
        else if (aliceScorediff < 0) return "Bob";
        else return "Tie";
    }

};

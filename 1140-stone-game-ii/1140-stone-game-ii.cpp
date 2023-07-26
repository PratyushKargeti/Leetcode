class Solution {
public:
    //ind: The current index in the piles vector.
    //m: The maximum number of stones a player can pick in one turn.
    //player: The current player (0 for Alice, 1 for Bob).
    //dp: The memoization table to store the computed results for subproblems.
    //piles: The input vector of piles.
    //n: The total number of piles.

    //note dimensions are dp[n+1][n+1][2] since ind can go from 0 to n(n because that is base case,so n+1 states) , m goes from 1 to n (but for base case no pile to pick so overall we can take n+1 states) , player are 2(alice and bob)
    
    int solve(int ind , int m, int player,vector<vector<vector<int>>>& dp, vector<int>& piles,int n) {
        if(ind == n) return 0;
        if(dp[ind][m][player]!=-1)  return dp[ind][m][player];
        
        
        int score;
        if(player==0) score = INT_MIN; //maximise alice's score
        else  score = INT_MAX; //minimise alice's score
        int currsum=0;

        //iterating through all possible moves player can make(x)
        //if 2*m exceeds array limit,then n-ind represents remaining piles from current index
        for(int x=1;x<=min(2*m,n-ind);x++) 
        {
            currsum+=piles[ind+x-1]; //since x is one-based indexing 
            
            if(player==0)   //alice's optimal play(maximising her score)
                score = max(score, currsum + solve(ind+x,max(m,x),1,dp,piles,n));//ind+x is used to move to the next state or pile after picking x piles from the current pile. 
            else //bob's optimal play 
                score = min(score, solve(ind+x,max(m,x),0,dp,piles,n));
                //Bob will minimise the best score that Alice can achieve from the next state(which is represented by solve fn), as he wants to achieve the best possible outcome for himself while limiting Alice's score.
        }
        return dp[ind][m][player] = score;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));       
        return solve(0,1,0,dp,piles,n);
    }
};

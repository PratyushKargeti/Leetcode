class Solution {
public:
    //for (i,j) in dp table fill how many squares endpoint is at dp(i,j)
    //after that sum all elements of dp table
    int countSquares(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        //only one square can be made for each entry of 1 in first row & first column //so copy
        for(int i=0;i<m;i++) dp[i][0]=mat[i][0];//copy 1st row
        for(int i=0;i<n;i++) dp[0][i]=mat[0][i];//copy 1st col
        
        //to fill dp(i,j) for other cases starting from mat(1,1), we take minimal of no. of squares formed at upper 
        //left diagonal index,upper index and left index of dp table and add one for biggest square ending at (i,j)  
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==1)
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                else
                    dp[i][j]=0;
            }
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=dp[i][j];
            }
        }
        return sum;
    }
    //tc-> O(m*n) for m*n matrix
    //sc-> O(m*n) for m*n dp table
};

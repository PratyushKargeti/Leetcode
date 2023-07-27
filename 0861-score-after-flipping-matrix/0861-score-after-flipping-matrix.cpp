class Solution {
public:
    //STRATEGY
// 1) flip rows that start with 0 (pretty obvious as we need max binary no. in any row in order to maximise overall score)
// 2) flip cols that have more zeroes than ones(we should prioritize flipping columns that have more 0's than 1's. Flipping such columns will increase the binary numbers' values in the corresponding rows)
// 3) find sum of binary number in each row
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
		// Step 1
        for(int i=0;i<m;i++) 
        {
            if(grid[i][0]==0)  
            {
                for(int j=0;j<n;j++) 
                    grid[i][j]=1-grid[i][j];
            }
        }
        
		// Step 2
        for(int j=0;j<n;j++) 
        {
            int ones=0,zeroes=0;
            for(int i=0;i<m;i++) 
            {
                if(grid[i][j]==1) ones++;
                else zeroes++;
            }
            if(zeroes>=ones) 
            {
                for(int i=0;i<m;i++) 
                    grid[i][j]=1-grid[i][j];
            }
        }

		//Step 3
        int score=0;
        for(int i=0;i<m;i++)
        {
            int num=0,shift=0;
            for(int j=n-1;j>=0;j--) 
            {
                if(grid[i][j]==1)
                {
                    num+=1<<shift;
                }
                shift++;
            }
            score+=num;
        }
        return score;
    }
};
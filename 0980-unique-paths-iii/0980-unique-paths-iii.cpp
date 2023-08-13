class Solution {
public:
    //this is simple dfs->marking the visited cells with -1 and counting the cells we passed.
    int solve(int i,int j,int m,int n,int validsteps,vector<vector<int>>&grid,int valcount)
    {
        if(i<0 || j<0 || i>m-1 || j> n-1 || grid[i][j]==-1)
            return 0;
        if(grid[i][j]==2)
        {
            if(valcount==validsteps)
                return 1;
            return 0;
        } 
        grid[i][j]=-1; //now cannot comeback on this
        int paths=solve(i - 1, j, m, n, validsteps, grid, valcount + 1)+solve(i + 1, j, m, n, validsteps, grid, valcount + 1)+solve(i, j - 1, m, n, validsteps, grid, valcount + 1)+solve(i, j + 1, m, n, validsteps, grid, valcount + 1);
        grid[i][j] = 0; // backtrack: mark the square as empty again
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int s1,s2,validsteps=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    s1=i;
                    s2=j;
                }
                if(grid[i][j]!=-1)
                    validsteps++;
                
            }
        }
        int ans=solve(s1,s2,m,n,validsteps,grid,1);
        return ans;
    }
};
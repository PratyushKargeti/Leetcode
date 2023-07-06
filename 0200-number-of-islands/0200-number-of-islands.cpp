class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        vector<vector<int>>moves{{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i = 0; i < moves.size(); i++)
            {
                int newrow = x + moves[i][0];
                int newcol = y + moves[i][1];
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol] == '1' && visited[newrow][newcol] == 0)
                {
                    q.push({newrow, newcol});
                    visited[newrow][newcol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]=='1' && visited[row][col]==0)
                {
                    count++;
                    bfs(row,col,grid,visited);
                }
            }
        }
        return count;
    }
};
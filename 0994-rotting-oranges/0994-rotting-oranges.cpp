class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) //push rotten oranges into queue with 0 time
                {
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        vector<vector<int>>moves{{-1,0},{1,0},{0,1},{0,-1}};
        int anstime=0;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            anstime=max(anstime,time); //since we need pair with largest time
            for(int i=0;i<moves.size();i++)
            {
                int newx=x+moves[i][0];
                int newy=y+moves[i][1];
                if(newx>=0 && newx<m && newy>=0 && newy<n && visited[newx][newy]==false && grid[newx][newy]==1)
                {
                    q.push({{newx,newy},time+1}); // since bfs is used nearest unrotten oranges to a rotten orange will be give increased time(+1)
                    visited[newx][newy]=true;
                }
            }
        }
        //check for still left unrotten oranges
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false && grid[i][j]==1)
                    return -1;
            }
        }
        return anstime;
    }
};
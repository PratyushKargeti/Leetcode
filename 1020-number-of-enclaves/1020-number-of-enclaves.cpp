class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && visited[i][j]==false && grid[i][j]==1)
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        vector<vector<int>>moves{{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int fronti=q.front().first;
            int frontj=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newi=fronti+moves[i][0];
                int newj=frontj+moves[i][1];
                if(newi>=0 && newi<m && newj>=0 && newj<n && visited[newi][newj]==false && grid[newi][newj]==1) 
                {   
                    q.push({newi,newj});
                    visited[newi][newj]=true;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(grid[i][j]==1 && visited[i][j]==false)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
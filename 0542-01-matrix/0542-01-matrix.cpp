class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            int fronti=q.front().first.first;
            int frontj=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newi=fronti+moves[i][0];
                int newj=frontj+moves[i][1];
                if(newi>=0 && newi<m && newj>=0 && newj<n && mat[newi][newj]==1 && visited[newi][newj]==false)
                {
                    q.push({{newi,newj},dis+1});
                    visited[newi][newj]=true;
                    ans[newi][newj]=dis+1;
                }
            }
        }
        return ans;
    }
};
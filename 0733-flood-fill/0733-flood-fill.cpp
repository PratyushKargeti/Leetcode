class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        vector<vector<int>>moves{{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<moves.size();i++)
            {
                int newrow=x+moves[i][0];
                int newcol=y+moves[i][1];
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && visited[newrow][newcol]==0 && image[newrow][newcol]==image[sr][sc])
                {
                    image[newrow][newcol]=color;
                    q.push({newrow,newcol});
                    visited[newrow][newcol]=true;
                }
            }
        }
        image[sr][sc]=color;
        return image;
    }
};
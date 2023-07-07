class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //any O which is connected to boundary O is useless(no conversion)
        //all remaining O's which are within boundary are useful(convertible)
        queue<pair<int,int>>q;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O')
                {
                    q.push({i,j}); //push all boundary O's in queue
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
                if(newi>=0 && newi<m && newj>=0 && newj<n && visited[newi][newj]==false && board[newi][newj]=='O')
                {
                    q.push({newi,newj}); //useless 'O' which will not be converted into 'X' will be pushed in queue
                    visited[newi][newj]=true;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==false)
                    board[i][j]='X'; //useful unvisited O's must be surrounded all by X so convertible
            }
        }
    }
};
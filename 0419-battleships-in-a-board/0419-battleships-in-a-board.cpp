class Solution {
public:
    void dfs(int fronti,int frontj,vector<vector<char>>&board,vector<vector<int>>&visited,vector<vector<int>>&moves,int m,int n)
    {
        visited[fronti][frontj]=true;
        for(int i=0;i<moves.size();i++)
        {
            int newi=fronti+moves[i][0];
            int newj=frontj+moves[i][1];
            if(newi>=0 && newi<m && newj>=0 && newj<n && visited[newi][newj]==0 && board[newi][newj]=='X')
            {
                dfs(newi,newj,board,visited,moves,m,n);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>moves{{1,0},{-1,0},{0,1},{0,-1}};
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X' && visited[i][j]==0)
                {
                    count++;
                    dfs(i,j,board,visited,moves,m,n);
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    bool dfs(int ind,int i,int j,vector<vector<int>>&moves,vector<vector<char>>&board,string&word)
    {
        if(ind==word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[ind]) return false;
        char originalchar=board[i][j];
        board[i][j]='#';
        for(int c=0;c<moves.size();c++)
        {
            int newi=i+moves[c][0];
            int newj=j+moves[c][1];
            if(dfs(ind+1,newi,newj,moves,board,word))
                return true;
        }
        board[i][j]=originalchar; //backtrack
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && dfs(0,i,j,moves,board,word))
                    return true;
            }
        }
        return false;
    }
};
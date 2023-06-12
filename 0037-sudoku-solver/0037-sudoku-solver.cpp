class Solution {
public:
    bool issafe(vector<vector<char>>&board,int i,int j,char ch)
    {
        for(int p=0;p<9;p++)
        {
            if(board[i][p]==ch) //same row check
                return false;
            if(board[p][j]==ch) //same column check
                return false;
            if(board[(i/3)*3+p/3][(j/3)*3+p%3]==ch)  //same block check
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(issafe(board,i,j,ch))
                        {
                            board[i][j]=ch;  
                            if(solve(board)==true) //solve rest of the board
                                return true; 
                            board[i][j]='.'; //current digit is invalid
                        }
                    }
                    return false;  //if no digit was valid on current empty cell
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
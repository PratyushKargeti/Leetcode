class Solution {
public:
bool issafe(int row, int col, vector<vector<char>>& board, char ch) {
    for (int i = 0; i < 9; i++) {
        if (i != col && board[row][i] == ch) // same row check
            return false;
        if (i != row && board[i][col] == ch) // same column check
            return false;
        
        int startRow = 3 * (row / 3) + i / 3;
        int startCol = 3 * (col / 3) + i % 3;
        if ((startRow != row || startCol != col) && board[startRow][startCol] == ch) // same block check
            return false;
    }
    return true;
}

    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch=board[i][j];
                if(ch!='.')
                {
                    if(issafe(i,j,board,ch)==false)
                        return false;
                }
            }
        }
        return true;
   }
};
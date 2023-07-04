class Solution {
public:
bool issafe(int row, int col, vector<vector<char>>& board) {
    char ch = board[row][col]; // value in the current cell

    // Check same row
    for (int i = 0; i < 9; i++) {
        if (i != col && board[row][i] == ch)
            return false;
    }

    // Check same column
    for (int i = 0; i < 9; i++) {
        if (i != row && board[i][col] == ch)
            return false;
    }

    // Check same block
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (i != row && j != col && board[i][j] == ch)
                return false;
        }
    }

    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(board[i][j]!='.'){
               if(issafe(i,j,board)==false)
               return false;
           }
       }
    }
return true;
   
    }
};
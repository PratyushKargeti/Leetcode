class Solution {
public:
    bool issafe(int currRow,vector<int>&col)
    {
        for(int row=0;row < currRow;row++)
        {
            if(col[currRow]==col[row] || abs(col[currRow]-col[row])==currRow-row)
                return false;
        }
        return true;
    }
    void place(int i,int n,vector<int>&col,vector<string>&board,vector<vector<string>>&ans)
    {
        if(i==n)
        {
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++)
        {
            col[i]=j;
            if(issafe(i,col))
            {
                board[i][j]='Q';
                place(i+1,n,col,board,ans);
                board[i][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int>col(n);
        vector<string> board(n);
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            board[i]=string(n,'.');
        }
        place(0,n,col,board,ans);
        return ans;
    }
};


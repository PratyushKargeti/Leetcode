class Solution {
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&lowerdiagonal,vector<int>&upperdiagonal,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(!leftrow[row] && !lowerdiagonal[row+col] && !upperdiagonal[n-1+col-row])
            {
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                solve(col+1,board,ans,leftrow,lowerdiagonal,upperdiagonal,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        //maintain hashes
        vector<int>leftrow(n,0);
        vector<int>lowerdiagonal(2*n-1,0);
        vector<int>upperdiagonal(2*n-1,0);
        solve(0,board,ans,leftrow,lowerdiagonal,upperdiagonal,n);
        return ans;
    }
};


class Solution {
public:
    void solve(int col,int &count, vector<int>&leftrow,vector<int>&lowerdiagonal,vector<int>&upperdiagonal,int n)
    {
        if(col==n)
        {
            count++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(!leftrow[row]&&!lowerdiagonal[row+col]&&!upperdiagonal[n-1+col-row])
            {
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                solve(col+1,count,leftrow,lowerdiagonal,upperdiagonal,n);
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int>leftrow(n,0);
        vector<int>lowerdiagonal(2*n-1,0);
        vector<int>upperdiagonal(2*n-1,0);
        int count=0;
        solve(0,count,leftrow,lowerdiagonal,upperdiagonal,n);
        return count;
    }
};
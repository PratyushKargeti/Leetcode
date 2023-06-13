class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { 
        int n=matrix.size();
        vector<vector<int>>adj(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adj[j][n-i-1]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=adj[i][j];
            }
        }
    }
};
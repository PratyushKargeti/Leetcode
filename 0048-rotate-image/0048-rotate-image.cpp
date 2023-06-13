class Solution {
public:
    void rotate(vector<vector<int>>& mat) { 
        int n=mat.size();
        //reverse matrix rows
        reverse(mat.begin(),mat.end());
        
        //transpose the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }
    }
};
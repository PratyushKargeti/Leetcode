class Solution {
public:
    void rotate(vector<vector<int>>& mat) { 
        int n=mat.size();
        //reverse matrix rows
        reverse(mat.begin(),mat.end());
        
        //7 8 9
        //4 5 6
        //1 2 3
        
        //transpose the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }

        //i=0 
        // mat[0][0] /mat[0][0]
        // mat[0][1] /mat[1][0]
        // mat[0][2] /mat[2][0]
        //i=1
        // mat[1][1] /mat[1][1]
        // mat[1][2] /mat[2][1]
        //i=2
        // mat[2][2] /mat[2][2]
    }
};
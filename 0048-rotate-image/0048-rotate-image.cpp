class Solution {
public:
    void rotate(vector<vector<int>>& mat) { 
        int n=mat.size();
        reverse(mat.begin(),mat.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }
    }
};
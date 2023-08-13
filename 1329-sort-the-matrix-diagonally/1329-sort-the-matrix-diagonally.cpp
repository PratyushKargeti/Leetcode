class Solution {
public:
//Every diagonal has it's has it's own unique id and that id = difference of indices of elements present on that diagonal.
//The i - j expression is used to calculate the diagonal id for each element, which is the key used in the diag map to group elements on the same diagonal.
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};
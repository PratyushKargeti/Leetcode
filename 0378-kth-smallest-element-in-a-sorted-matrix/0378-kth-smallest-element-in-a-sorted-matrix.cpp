class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>res;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                res.push_back(matrix[i][j]);
            }
        }
        multiset<int> MS;
        MS.insert(res.begin(),res.end());
        res.clear();
        for(int i: MS)
        {
            res.push_back(i);
        }
        return(res[k-1]);
    }
};
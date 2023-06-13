class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid[0].size();
        for(int j=0;j<n;j++)
        {
            vector<int>col;
            for(int i=0;i<n;i++)
            {
                col.push_back(grid[i][j]);
            }
            grid.push_back(col);
        }
        int count=0;
        int ns=grid.size(); //newsize
        for(int i=0;i<ns/2;i++)
        {
            for(int j=ns/2;j<ns;j++)
            {
                if(grid[i]==grid[j])
                    count++;
            }
        }
        return count;
    }
};
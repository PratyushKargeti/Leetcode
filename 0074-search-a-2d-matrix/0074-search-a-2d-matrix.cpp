class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(int i=0;i<matrix.size();i++)
        // {
        //     for(int j=0;j<matrix[i].size();j++)
        //     {
        //         if(matrix[i][j]==target)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int i=0;
        int m=matrix.size();
        int n=matrix[i].size();
        for(int i=0;i<m;i++)
        {
            int low=0;
            int high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target)
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
        return false;
    }
};
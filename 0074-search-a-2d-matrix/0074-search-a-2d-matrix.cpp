class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
         //this way is valid only for this question..here The first integer of each row is greater than the last integer of the previous row.
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=m*n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mat[mid/n][mid%n]==target)
                return true;
            else if(mat[mid/n][mid%n]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return false;
        //O(m*n)
        // for(int i=0;i<mat.size();i++)
        // {
        //     for(int j=0;j<mat[i].size();j++)
        //     {
        //         if(mat[i][j]==target)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        //O(m*log(n))
        // int i=0;
        // int m=mat.size();
        // int n=mat[i].size();
        // for(int i=0;i<m;i++)
        // {
        //     int low=0;
        //     int high=n-1;
        //     while(low<=high)
        //     {
        //         int mid=low+(high-low)/2;
        //         if(mat[i][mid]==target)
        //             return true;
        //         else if(mat[i][mid]>target)
        //             high=mid-1;
        //         else
        //             low=mid+1;
        //     }
        // }
        // return false;
    }
};
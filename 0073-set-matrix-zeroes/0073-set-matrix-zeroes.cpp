class Solution {
public: 
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        //variables to check case of first row and first column separately
        bool firstrow=false;
        bool firstcol=false;
        for(int i=0;i<n;i++) 
        {
            if(mat[0][i]==0)
                firstrow=true;
        }
        for(int i=0;i<m;i++)
        {
            if(mat[i][0]==0)
                firstcol=true;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++) 
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j]=0;
            }
        }
        if(firstrow)
        {
            for(int i=0;i<n;i++)
                mat[0][i]=0;
        }
        if(firstcol)
        {
            for(int i=0;i<m;i++)
                mat[i][0]=0;
        }
    }
};
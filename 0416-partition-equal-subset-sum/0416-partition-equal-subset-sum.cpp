class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<bool>> t(n+1,vector<bool>(target+1));
        for(int i=0;i<=n;i++)
            t[i][0]=true;
        for(int i=1;i<=n;i++)
        {
            int curr=nums[i-1];
            for(int j=1;j<=target;j++)
            {
                if(curr<=j)
                {
                    t[i][j]=t[i-1][j-curr] || t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][target];
    }
};
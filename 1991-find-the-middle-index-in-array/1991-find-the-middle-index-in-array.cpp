class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++)
        // {
        //     int lsum=0,rsum=0;
        //     for(int j=0;j<i;j++)
        //         lsum+=nums[j];
        //     for(int k=i+1;k<nums.size();k++)
        //         rsum+=nums[k];
        //     if(lsum==rsum)
        //         return i;
        // }
        // return -1;   
        int sum=0,leftsum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
            if(leftsum==sum)
                return i;
            leftsum+=nums[i];
        }
        return -1; 
    }
};
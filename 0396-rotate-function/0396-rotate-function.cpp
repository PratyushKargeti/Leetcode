class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        //F(k) = F(k-1) + sum(nums) - n * nums[n-k]
        int n=nums.size();
        int maxi=0; //has to be minimum here-> 0
        int sum=0;
        int f=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            f+=i*nums[i];
        }
        maxi=f;
        for(int k=1;k<n;k++)
        {
            f=f+sum-n*nums[n-k];
            maxi=max(maxi,f);
        }
        return maxi;
    }
};
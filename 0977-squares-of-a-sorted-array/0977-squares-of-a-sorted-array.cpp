class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //bruteforce
        // vector<int>ans;
        // for(int i=0;i<nums.size();i++)
        // {
        //     nums[i]=nums[i]*nums[i];
        //     ans.push_back(nums[i]);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        //optimized(two pointers)
        int n=nums.size();
        vector<int>ans(n);
        int l=0;
        int r=n-1;
        for(int i=n-1;i>=0;i--)
        {
            int sql=nums[l]*nums[l];
            int sqr=nums[r]*nums[r];
            if(sql>sqr)
            {
                ans[i]=sql;
                l++;
            }
            else
            {
                ans[i]=sqr;
                r--;
            }
        }
        return ans;

    }
};
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // int count=0;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {                
        //         if(abs(nums[i]-nums[j])==k)
        //             count++;
        //     }
        // }        
        // return count;

        unordered_map<int,int>m;
        int res=0;
        for(int i: nums)
        {
            m[i]++;
            res+=m[i-k]+m[i+k];
        }
        return res;

    }
};
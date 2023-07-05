class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int start=0,i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                l=max(l,i-start);
                start=i+1;
            }
        }
        l=max(l,i-start);
        return l;
    }
};
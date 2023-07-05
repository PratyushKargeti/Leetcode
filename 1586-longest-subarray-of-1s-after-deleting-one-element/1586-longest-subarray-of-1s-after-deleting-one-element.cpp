class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocount=0;  // Number of zero's in the window.
        int l=0;
        int start=0;// Left end of the window.
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zerocount++;
            // Shrink the window until the zero counts come under the limit.
            while(zerocount>1)
            {
                if(nums[start]==0)
                    zerocount--;
                start++;
            }
            l=max(l,i-start); 
        }
        return l;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int start=0,i;
        // for(i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==0)
        //         k--;
        //     if(k<0 && nums[start++]==0)
        //         k++;
        // }
        // return i-start;
        int zerocount=0;  // Number of zero's in the window.
        int l=0;
        int start=0;// Left end of the window.
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zerocount++;
            // Shrink the window until the zero counts come under the limit.
            while(zerocount>k)
            {
                if(nums[start]==0)
                    zerocount--;
                start++;
            }
            l=max(l,i-start+1); 
        }
        return l;
    }
};
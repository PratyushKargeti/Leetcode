class Solution {
public:
    int sum(int mid,vector<int>&nums)
    {
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=ceil((double)nums[i]/mid);
        }
        return s;
    }
    //just like koko,bouquets, we can apply binary search as search space where we can get an answer is fixed from 1 to max element in nums(these are possible divisors)
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=*max_element(begin(nums),end(nums));
        int low=1;
        int high=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(sum(mid,nums)<=threshold)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};